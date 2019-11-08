#include "SymbolTable.h"

#include <cassert>
std::unordered_map<std::string, OperandSize>  SymbolTable::operandSizeTable_{
	{"Byte",OperandSize::BYTE},
	{"Word",OperandSize::WORD},
	{"DWord",OperandSize::DWORD},
	{"QWord",OperandSize::QWORD},
};

std::unordered_map<std::string, OpCode> SymbolTable::operationTable_{
	{"ASSIGN",OpCode::ASSIGN},
	{"ADD",OpCode::ADD},
	{"ADC",OpCode::ADC},
	{"SUB",OpCode::SUB},
	{"SBB",OpCode::SBB},
	{"MUL",OpCode::MUL},
	{"IMUL",OpCode::IMUL},
	{"DIV",OpCode::DIV},
	{"IDIV",OpCode::IDIV},
	{"NEG",OpCode::NEG},
	{"CAST",OpCode::CAST},
	{"AND",OpCode::AND},
	{"OR",OpCode::OR},
	{"XOR",OpCode::XOR},
	{"NOR",OpCode::NOR},
	{"NAND",OpCode::NAND},
	{"NOT",OpCode::NOT},
	{"SHL",OpCode::SHL},
	{"SHR",OpCode::SHR},
	{"ROL",OpCode::ROL},
	{"ROR",OpCode::ROR},
	{"JMP",OpCode::JMP},
	{"CALL",OpCode::CALL},
	{"NOP",OpCode::NOP},
	{"GFLR",OpCode::GFLR},
	{"SFLR",OpCode::SFLR},
	{"LOAD",OpCode::LOAD},
	{"LDREL",OpCode::LDREL},
	{"STORE",OpCode::STORE},
	{"STREL",OpCode::STREL},
	{"MOVE",OpCode::MOV},
	{"SWAP",OpCode::SWP}

};

std::unordered_map<std::string, Condition>  SymbolTable::conditionTable_{
	{"E",Condition::E},
	{"Z",Condition::Z},
	{"NE",Condition::NE},
	{"NZ",Condition::NZ},
	{"A",Condition::A},
	{"NBE",Condition::NBE},
	{"AE",Condition::AE},
	{"NB",Condition::NB},
	{"B",Condition::B},
	{"NAE",Condition::NAE},
	{"BE",Condition::BE},
	{"NA",Condition::NA},
	{"G",Condition::G},
	{"NLE",Condition::NLE},
	{"GE",Condition::GE},
	{"NL",Condition::NL},
	{"L",Condition::L},
	{"NGE",Condition::NGE},
	{"LE",Condition::LE},
	{"NG",Condition::NG},
	{"O",Condition::O},
	{"NO",Condition::NO},
	{"S",Condition::S},
	{"NS",Condition::NS},
};

std::optional<OperandSize> SymbolTable::operandSize(const std::string& operandSize) {
	auto iter = operandSizeTable_.find(operandSize);

	if (iter == operandSizeTable_.end()) return std::make_optional<OperandSize>();

	return std::make_optional(iter->second);
}

std::optional<OpCode> SymbolTable::operationCode(const std::string& operationCode) {
	auto iter = operationTable_.find(operationCode);

	if (iter == operationTable_.end()) return std::make_optional<OpCode>();

	return std::make_optional<OpCode>(iter->second);
}

std::optional<Condition> SymbolTable::condition(const std::string& conditionString) {
	auto iter = conditionTable_.find(conditionString);
	
	if (iter == conditionTable_.end()) return std::make_optional<Condition>();
	
	return std::make_optional(iter->second);
}

std::optional<ArgType> SymbolTable::argumentType(const std::string& argument) {
	assert(argument.size() > 2);

	switch (argument[0]) {
		case 'R':	return ArgType::GPR; break;
		case 'A':	return ArgType::AR; break;
		default: return ArgType::NUM;		//TODO handle the case when is jibberish.
	}
}