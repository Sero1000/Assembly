#ifndef FUNCTION_H
#define FUNCTION_H

#include "Instruction.h"

#include <string>

class Function {
public:
	Function(const std::string& name);

	Function() = default;

	Function(const Function& other) = default;
	Function& operator=(const Function& other) = default;

	Function(Function&& other) = default;
	Function& operator=(Function&& other) = default;

	std::string Name() const { return name_; }
	InstructionVector Code() const { return code_; }

	void appendInstruction(const Instruction& instruction);

private:
	std::string name_;
	InstructionVector code_;
};

using FunctionVector = std::vector<Function>;

#endif