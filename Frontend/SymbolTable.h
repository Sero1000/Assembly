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

	static const std::string MainSectionHeader;
	static const std::string DataSectionHeader;
	static const std::string CodeSectionHeader;
	static const std::string StackSectionHeader;
private:
	static const std::unordered_map<std::string, OpCode> operationTable_;
	static const std::unordered_map<std::string, OperandSize> operandSizeTable_;
	static const std::unordered_map<std::string, Condition> conditionTable_;
};

#endif