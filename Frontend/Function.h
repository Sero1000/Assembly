#ifndef FUNCTION_H
#define FUNCTION_H

#include "Instruction.h"

#include <string>

class Function {
	friend void operator<<(std::fstream& file, const Function& function);
public:
	Function(const std::string& name);

	Function() = default;

	Function(const Function& other) = default;
	Function& operator=(const Function& other) = default;

	Function(Function&& other) = default;
	Function& operator=(Function&& other) = default;

	std::string name() const { return name_; }
	size_t size() const { return code_.size(); }

	void appendInstruction(const Instruction& instruction);

private:
	std::string name_;
	InstructionVector code_;
};

using FunctionVector = std::vector<Function>;

#endif