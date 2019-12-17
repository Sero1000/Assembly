#include "Function.h"

#include <fstream>

Function::Function(const std::string& name) : name_(name)
{

}

void Function::appendInstruction(const Instruction& instruction) 
{
	code_.emplace_back(instruction);
}

void operator<<(std::fstream& file, const Function& function) {
	for (auto iter = function.code_.cbegin(); iter != function.code_.cend(); ++iter) {
		file.write(reinterpret_cast<const char*>(&(*iter)), sizeof(*iter));
	}
}