#include "MainSection.h"

MainSection::MainSection(int address) : mainFunctionAddress_(address){

}

std::fstream& operator<<(std::fstream& file, const MainSection& mainSection) {
	file.write(reinterpret_cast<const char*>(&mainSection.mainFunctionAddress_), sizeof(mainSection.mainFunctionAddress_));
	
	return file;
}