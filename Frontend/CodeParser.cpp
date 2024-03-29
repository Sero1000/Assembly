#include "CodeParser.h"
#include "ParserUtilities.h"
#include "CodeSection.h"
#include "SymbolTable.h"

#include <string>

CodeSection CodeParser::parse(std::ifstream& file,const DataSection& dataSection) const {
	CodeSection codeSection;
	
	std::string line = "";

	std::getline(file, line);
	while (line != SymbolTable::MainSectionHeader) {
		if (line.empty()) { std::getline(file, line); continue; }

		StringVector tokens = ParserUtilities::split(line);
		std::string name = tokens[1];

		Function function;
		if(tokens.size() != 2)
			function = defineFunction(name, file,dataSection);
		codeSection.addFunction(function);
		
		std::getline(file, line);
	}

	return codeSection;
}

Function CodeParser::defineFunction(const std::string& name,std::ifstream& file,const DataSection& dataSection) const{
	std::string line;
	std::getline(file, line);

	Function function(name);

	while (line != "ENDF") {
		StringVector tokens = ParserUtilities::split(line);
		Instruction instruction = parseInstruction(tokens,dataSection);

		function.appendInstruction(instruction);
		
		getline(file, line);
	}

	return std::move(function);
}

Instruction CodeParser::parseInstruction(const StringVector& tokens,const DataSection& dataSection) const {
	Instruction instruction;

	//TODO a lot of if/elses

	int opCodeIndex = 0;
	int operandSizeIndex = 1;
	int conditionCodeIndex = 2;
	int firstArgIndex = 3;
	int secondArgIndex = 4;
	
	if (auto operationCode = SymbolTable::operationCode(tokens[opCodeIndex]);operationCode.has_value()) {
		instruction.opCode_ = operationCode.value();
	}
	else {
		//TODO report invalid instruction.
	}
	
	if (auto operandSize = SymbolTable::operandSize(tokens[operandSizeIndex]); operandSize.has_value()) {
		instruction.operandSize_ = operandSize.value();
	}
	else {
		instruction.operandSize_ = OperandSize::DWORD;
		--conditionCodeIndex;
		--firstArgIndex;
		--secondArgIndex;
	}

	if (auto condition = SymbolTable::condition(tokens[conditionCodeIndex]);condition.has_value()) {
		instruction.condition_ = condition.value();
	}
	else {
		instruction.condition_ = Condition::NOCOND;
		--firstArgIndex;
		--secondArgIndex;
	}
	
	if (auto argumentType = SymbolTable::argumentType(tokens[firstArgIndex]); argumentType.has_value()) {
		instruction.argType1_ = argumentType.value();
	}

	if (auto argumentType = SymbolTable::argumentType(tokens[secondArgIndex]); argumentType.has_value()) {
		instruction.argType2_ = argumentType.value();
	}

	if (instruction.argType1_ == ArgType::NUM) {
		instruction.arg1_ = std::stoi(tokens[firstArgIndex]);
	}
	else if (instruction.argType1_ == ArgType::ADDRESS) {
		instruction.arg1_ = dataSection.addressOf(tokens[firstArgIndex]);
	}
	else {
		const std::string& argInString = tokens[secondArgIndex];
		instruction.arg1_ = std::stoi(std::string(argInString.begin() + 1, argInString.end()));
	}

	if (instruction.argType2_ == ArgType::NUM) {
		instruction.arg2_ = std::stoi(tokens[firstArgIndex]);
	}
	else if (instruction.argType2_ == ArgType::ADDRESS) {
		instruction.arg2_ = dataSection.addressOf(tokens[secondArgIndex]);
	}
	else {
		const std::string& argInString = tokens[secondArgIndex];
		instruction.arg2_ = std::stoi(std::string(argInString.begin() + 1, argInString.end()));
	}

	return instruction;
}