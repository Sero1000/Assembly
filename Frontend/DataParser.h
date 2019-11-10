#ifndef DATAPARSER_H
#define DATAPARSER_H

#include "DataSection.h"

#include <memory>

class DataParser {
public:
	DataParser();

	DataParser(const DataParser& other) = default;
	DataParser& operator= (const DataParser & other) = default;

	DataParser(DataParser&& other) = default;
	DataParser& operator=(DataParser&& other) = default;

	DataSection parse(std::ifstream& stream);
private:
	template<typename T>
	void createVariable(DataSection& dataSection,const std::string& name, const std::string& value) const;

	template<>
	void createVariable<char>(DataSection& dataSection, const std::string& name, const std::string& value) const;

	template<typename T>
	std::vector<T> getArrayFromLiteral(const StringVector& values) const;

	CharVector getArrayFromLiteral(const std::string& values) const;
};


using DataParserUPtr = std::unique_ptr<DataParser>;
using DataParserShPtr = std::shared_ptr<DataParser>;
using DataParserWPtr = std::weak_ptr<DataParser>;

#endif