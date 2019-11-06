#include "CodeSection.h"

void CodeSection::DefineFunction(Function& function) {
	code_.emplace_back(function);
}