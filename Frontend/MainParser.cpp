#include "MainParser.h"
#include "SymbolTable.h"

MainSection MainParser::parse(std::ifstream& file, const CodeSection& codeSection) const {
	std::string line;

	std::getline(file, line);
	if (codeSection.functionDeclared(line)) {
		return MainSection(codeSection.addressOf(line));
	}
	//TODO
	//Else throw parsing exception.
}