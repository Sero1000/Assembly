#include "CodeParser.h"
#include "ParserUtilities.h"
#include "CodeSection.h"

#include <string>

CodeSection CodeParser::Parse(std::ifstream& file) const {
	std::string line = "";

	std::getline(file, line);
	while (line != "") {
		StringVector tokens = ParserUtilities::split(line);
		std::string name = tokens[1];

		defineFunction(name,file);
		std::getline(file, line);
	}

	return CodeSection();
}

void CodeParser::defineFunction(const std::string& name,std::ifstream& file) const{
	std::string line;
	std::getline(file, line);

	Function function(name);

	while (line != "ENDF") {
		StringVector tokens = ParserUtilities::split(line);
		Instruction instruction = parseInstruction(tokens);

		function.appendInstruction(instruction);
		
		getline(file, line);
	}
}

Instruction CodeParser::parseInstruction(const StringVector& tokens) const {
	//TODO
	return Instruction();
}