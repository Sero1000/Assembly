#ifndef CODEPARSER_H
#define CODEPARSER_H

#include <fstream>
#include "CodeSection.h"

class CodeParser {
public:
	CodeParser() = default;

	CodeParser(const CodeParser& other) = default;
	CodeParser& operator= (const CodeParser& other) = default;

	CodeParser(CodeParser&& other) = default;
	CodeParser& operator=(CodeParser&& other) = default;

	CodeSection Parse(std::ifstream& file) const;
private:
	Function defineFunction(const std::string& name, std::ifstream& file) const; 

	Instruction parseInstruction(const StringVector& tokens) const;
};

#endif