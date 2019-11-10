#ifndef CODEPARSER_H
#define CODEPARSER_H

#include "CodeSection.h"
#include "DataSection.h"

#include <fstream>
#include <memory>

class CodeParser {
public:
	CodeParser() = default;

	CodeParser(const CodeParser& other) = default;
	CodeParser& operator= (const CodeParser& other) = default;

	CodeParser(CodeParser&& other) = default;
	CodeParser& operator=(CodeParser&& other) = default;

	/*
	 *  A data section is neede for code sections parsing because of the variables
	 *  During parsing CodeParser has to know the addresses of the variables.
	 */

	CodeSection parse(std::ifstream& file,const DataSection& dataSecion) const;
private:
	Function defineFunction(const std::string& name, std::ifstream& file,const DataSection& dataSection) const; 

	Instruction parseInstruction(const StringVector& tokens,const DataSection& dataSection) const;
};

using CodeParserUPtr = std::unique_ptr<CodeParser>;
using CodeParserSPtr = std::shared_ptr<CodeParser>;
using CodeParserWPtr = std::weak_ptr<CodeParser>;

#endif