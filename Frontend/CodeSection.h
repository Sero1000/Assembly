#ifndef CODESECTION_H
#define CODESECTION_H

#include "../Frontend/TypeDefs.h"
#include "Function.h"

class CodeSection {
	CodeSection();

	CodeSection(const CodeSection& other) = default;
	CodeSection& operator=(const CodeSection& other) = default;

	CodeSection(CodeSection&& other) = default;
	CodeSection& operator=(CodeSection&& other) = default;

	void DefineFunction(Function& function);

private:
	FunctionVector code_;
};

#endif