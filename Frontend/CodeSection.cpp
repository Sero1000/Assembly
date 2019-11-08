#include "CodeSection.h"

void CodeSection::addFunction(Function& function) {
	code_.emplace_back(function);
}