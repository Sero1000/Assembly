#ifndef CODESECTION_H
#define CODESECTION_H

#include "../Frontend/TypeDefs.h"
#include "Function.h"

class CodeSection {
	friend std::fstream& operator<<(std::fstream& file, const CodeSection& codeSection);
public:
	CodeSection() = default;

	CodeSection(const CodeSection& other) = default;
	CodeSection& operator=(const CodeSection& other) = default;

	CodeSection(CodeSection&& other) = default;
	CodeSection& operator=(CodeSection&& other) = default;

	void addFunction(Function& function);

	int addressOf(const std::string& functionName) const;

	bool functionDeclared(const std::string& functionName) const;
private:
	FunctionVector code_;
};

std::fstream& operator<<(std::fstream& file, const CodeSection& codeSection);

#endif