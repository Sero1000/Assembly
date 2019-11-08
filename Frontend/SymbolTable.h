#ifndef SYMBOLS_H
#define SYMBOLS_H

#include "Instruction.h"

#include <unordered_map>
#include <optional>

class SymbolTable {
public:
	SymbolTable() = default;

	SymbolTable(const SymbolTable&) = default;
	SymbolTable& operator=(const SymbolTable&) = default;

	SymbolTable(SymbolTable&&) = default;
	SymbolTable& operator=(SymbolTable&&) = default;
	
	static std::optional<OperandSize> operandSize(const std::string&);
	static std::optional<OpCode> operationCode(const std::string&);
	static std::optional<Condition> condition(const std::string&);
	static std::optional<ArgType> argumentType(const std::string&);
private:
	static std::unordered_map<std::string, OpCode> operationTable_;
	static std::unordered_map<std::string, OperandSize> operandSizeTable_;
	static std::unordered_map<std::string, Condition> conditionTable_;
};

#endif