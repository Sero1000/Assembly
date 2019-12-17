#include "StackSection.h"

StackSection::StackSection(int size) : stackSize_(size) 
{

}

int StackSection::stackSize() const {
	return stackSize_;
}

std::fstream& operator<<(std::fstream& file, const StackSection& stackSection) {
	int stackSize = stackSection.stackSize();
	file .write(reinterpret_cast<char*>(&stackSize), sizeof(int));

	return file;
}