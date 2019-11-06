#ifndef PARSERUTILITIES_H
#define PARSERUTILITIES_H

#include <vector>
#include <string>

#include "TypeDefs.h"

namespace ParserUtilities {
	StringVector split(const std::string& line, char seperator = ' ');
	bool isVariableAnArray(const std::string& variableName);
	void trim(std::string&);
}

#endif
