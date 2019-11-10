#include "Backend/Compiler.h"

#include <fstream>

int main() {
	Compiler compiler;

	std::ifstream file("test.txt");

	compiler.compile(file);

	return 0;
}