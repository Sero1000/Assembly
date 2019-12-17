#ifndef MAINSECTION_H
#define MAINSECTION_H

#include "CodeSection.h"

#include <fstream>

class MainSection {
	friend std::fstream& operator<<(std::fstream& file, const MainSection& mainSection);
public:
	MainSection(int address);

	MainSection() = default;

	MainSection(const MainSection& other) = default;
	MainSection& operator=(const MainSection& other) = default;

	MainSection(MainSection&& other) = default;
	MainSection& operator=(MainSection&& other) = default;
private:
	int mainFunctionAddress_;
};

std::fstream& operator<<(std::fstream& file, const MainSection& mainSection);

#endif