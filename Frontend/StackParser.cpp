#include "StackParser.h"
#include "ParserUtilities.h"
#include "SymbolTable.h"

#include <string>

StackSection StackParser::parse(std::ifstream& file) const {	
	std::string line;

	while (line != SymbolTable::StackSectionHeader) {
		std::getline(file, line);
	}
	
	StringVector tokens = ParserUtilities::split(line);

	int stackSize = std::stoi(tokens.back());

	return StackSection(stackSize);
}