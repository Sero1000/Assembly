#ifndef STACKSECTION_H
#define STACKSECTION_H

#include <fstream>

class StackSection {
public:
	StackSection(int size);

	StackSection() = default;

	StackSection(const StackSection& other) = default;
	StackSection& operator=(const StackSection& other) = default;

	StackSection(StackSection&& other) = default;
	StackSection& operator=(StackSection&& other) = default;

	int stackSize() const;
private:
	int stackSize_;
};

std::fstream& operator<<(std::fstream& file, const StackSection&);

#endif