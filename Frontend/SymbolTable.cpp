#include "SymbolTable.h"

std::unordered_map<std::string, OperandSize>  SymbolTable::operandSizeTable_{
	{"Byte",OperandSize::BYTE},
	{"Word",OperandSize::WORD},
	{"DWord",OperandSize::DWORD},
	{"QWord",OperandSize::QWORD},
};

std::unordered_map<std::string, OpCode> SymbolTable::operationTable_{
	{"ASSIGN",OpCode::ASSIGN},
	{"ADD",OpCode::ADD},
	{"ADC",OpCode::ADC},
	{"SUB",OpCode::SUB},
	{"SBB",OpCode::SBB},
	{"MUL",OpCode::MUL},
	{"IMUL",OpCode::IMUL},
	{"DIV",OpCode::DIV},
	{"IDIV",OpCode::IDIV},
	{"NEG",OpCode::NEG},
	{"CAST",OpCode::CAST},
	{"AND",OpCode::AND},
	{"OR",OpCode::OR},
	{"XOR",OpCode::XOR},
	{"NOR",OpCode::NOR},
	{"NAND",OpCode::NAND},
	{"NOT",OpCode::NOT},
	{"SHL",OpCode::SHL},
	{"SHR",OpCode::SHR},
	{"ROL",OpCode::ROL},
	{"ROR",OpCode::ROR},
	{"JMP",OpCode::JMP},
	{"CALL",OpCode::CALL},
	{"NOP",OpCode::NOP},
	{"GFLR",OpCode::GFLR},
	{"SFLR",OpCode::SFLR},
	{"LOAD",OpCode::LOAD},
	{"LDREL",OpCode::LDREL},
	{"STORE",OpCode::STORE},
	{"STREL",OpCode::STREL},
	{"MOVE",OpCode::MOV},
	{"SWAP",OpCode::SWP}

};

std::unordered_map<std::string, Condition>  SymbolTable::conditionTable_{
	{"E",Condition::E},
	{"Z",Condition::Z},
	{"NE",Condition::NE},
	{"NZ",Condition::NZ},
	{"A",Condition::A},
	{"NBE",Condition::NBE},
	{"AE",Condition::AE},
	{"NB",Condition::NB},
	{"B",Condition::B},
	{"NAE",Condition::NAE},
	{"BE",Condition::BE},
	{"NA",Condition::NA},
	{"G",Condition::G},
	{"NLE",Condition::NLE},
	{"GE",Condition::GE},
	{"NL",Condition::NL},
	{"L",Condition::L},
	{"NGE",Condition::NGE},
	{"LE",Condition::LE},
	{"NG",Condition::NG},
	{"O",Condition::O},
	{"NO",Condition::NO},
	{"S",Condition::S},
	{"NS",Condition::NS},
};

OperandSize SymbolTable::getOperandSize(const std::string& operandSize) const {
	return operandSizeTable_[operandSize];
}

OpCode SymbolTable::getOperationCode(const std::string& operationCode) const {
	return operationTable_[operationCode];
}

Condition SymbolTable::getCondition(const std::string& conditionString) const {
	return conditionTable_[conditionString];
}