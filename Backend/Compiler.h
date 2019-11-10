#ifndef COMPILER_H
#define COMPILER_H

#include "../Frontend/DataParser.h"
#include "../Frontend/CodeParser.h"

#include <fstream>

class Compiler {
public:
	Compiler();

	void compile(std::ifstream& inputFile);
private:
	void write(std::ofstream& outputFile,const ByteVector&) const;
private:
	DataParserUPtr dataParser_;
	CodeParserUPtr codeParser_;
};

#endif