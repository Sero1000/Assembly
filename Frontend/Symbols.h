#ifndef SYMBOLS_H
#define SYMBOLS_H

#include "Instruction.h"
#include <unordered_map>

class SymbolTable {
public:
	SymbolTable() = default;

	SymbolTable(const SymbolTable&) = default;
	SymbolTable& operator=(const SymbolTable&) = default;

	SymbolTable(SymbolTable&&) = default;
	SymbolTable& operator=(const SymbolTable&) = default;

	OpSize getOperandSize(const std::string&) const;
	OpCode getOperationCode(const std::string&) const;
	Condition getCondition(const std::string&) const;
private:
	static std::unordered_map<std::string, OpSize> opSizeTable_;
	static std::unordered_map<std::string, OpCode> instructionTable_;
	static std::unordered_map<std::string, Condition> conditionTable_;

};

#endif