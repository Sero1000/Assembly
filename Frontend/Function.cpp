#include "Function.h"

Function::Function(const std::string& name) : name_(name)
{

}

void Function::appendInstruction(const Instruction& instruction) 
{
	code_.emplace_back(instruction);
}
