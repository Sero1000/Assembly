#include "CodeSection.h"
#include <algorithm>
#include <numeric>

void CodeSection::addFunction(Function& function) {
	code_.emplace_back(function);
}

int CodeSection::addressOf(const std::string& functionName) const {
	auto iter = std::find_if(code_.cbegin(), code_.cend(), [&functionName](const Function& function)
														{return function.name() == functionName; });

	return std::accumulate(code_.cbegin(), iter, 0, [](int sumSoFar, const Function& function1) 
														{return sumSoFar + function1.code().size(); });
}

bool CodeSection::functionDeclared(const std::string& functionName) const {
	auto iter = std::find_if(code_.cbegin(), code_.cend(), [&functionName](const Function& function) {return function.name() == functionName; });
	
	return iter == code_.cend();
}