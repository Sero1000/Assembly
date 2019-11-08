#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <cstdint>
#include <vector>

enum class OpCode : std::uint8_t
{
	ASSIGN = 0,
	ADD,
	ADC,
	SUB,
	SBB,
	MUL,
	IMUL,
	DIV,
	IDIV,
	NEG,
	CAST,
	AND,
	OR,
	XOR,
	NOR,
	NAND,
	NOT,
	SHL,
	SHR,
	ROL,
	ROR,
	JMP,
	CALL,
	NOP,
	GFLR,
	SFLR,
	LOAD,
	LDREL,
	STORE,
	STREL,
	MOV,
	SWP
};

enum class OperandSize : std::uint8_t
{
	NOSIZE = 0, 
	BYTE,
	WORD,
	DWORD, 
	QWORD 
};

enum class ArgType : std::uint8_t
{
	NUM = 0, 
	GPR, 
	AR, 
};

enum class Condition :std::uint8_t
{
	NOCOND = 0,
	E, 
	Z, 
	NE, 
	NZ, 
	A, 
	NBE, 
	AE, 
	NB, 
	B, 
	NAE, 
	BE, 
	NA, 
	G, 
	NLE, 
	GE, 
	NL, 
	L, 
	NGE, 
	LE, 
	NG, 
	O, 
	NO, 
	S, 
	NS
};

struct Instruction {
	OpCode opCode_;
	OperandSize operandSize_;
	ArgType argType1_, argType2_;
	Condition condition_;

	std::uint8_t arg1_;
	std::uint8_t arg2_;
};

using InstructionVector = std::vector<Instruction>;

#endif