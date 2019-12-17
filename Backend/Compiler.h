#ifndef COMPILER_H
#define COMPILER_H

#include "../Frontend/StackParser.h"
#include "../Frontend/DataParser.h"
#include "../Frontend/CodeParser.h"
#include "../Frontend/MainParser.h"

#include <fstream>
#include <memory>

class Compiler {
public:
	Compiler();

	void compile(std::ifstream& inputFile);
private:
	void write(std::ofstream& outputFile,const ByteVector&) const;
private:
	StackParserUPtr stackParser_;
	DataParserUPtr dataParser_;
	CodeParserUPtr codeParser_;
	MainParserUPtr mainParser_;
};

#endif