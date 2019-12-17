#ifndef STACKPARSER_H
#define STACKPARSER_H

#include "StackSection.h"

#include <fstream>

class StackParser {
public:
	StackParser() = default;

	StackParser(const StackParser& other) = default;
	StackParser& operator=(const StackParser& other) = default;

	StackParser(StackParser&& other) = default;
	StackParser& operator=(StackParser&& other) = default;

	StackSection parse(std::ifstream& file) const;
};

using StackParserUPtr = std::unique_ptr<StackParser>;
using StackParserSPtr = std::shared_ptr<StackParser>;
using StackParserWPtr = std::weak_ptr<StackParser>;

#endif