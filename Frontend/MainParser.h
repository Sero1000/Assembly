#ifndef MAINPARSER_H
#define MAINPARSER_H

#include "MainSection.h"
#include "CodeSection.h"

class MainParser {
public:
	MainParser() = default;

	MainParser(const MainParser& other) = default;
	MainParser& operator=(const MainParser& other) = default;

	MainParser(MainParser&& other) = default;
	MainParser& operator=(MainParser&& other) = default;

	MainSection parse(std::ifstream& fileStream, const CodeSection& codeSection) const;
};

using MainParserUPtr = std::unique_ptr<MainParser>;
using MainParserSPtr = std::shared_ptr<MainParser>;
using MainParserWPtr = std::weak_ptr<MainParser>;

#endif