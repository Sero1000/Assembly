#include "DataParser.h"
#include "ParserUtilities.h"
#include "TypeDefs.h"
#include "SymbolTable.h"

#include <string>
#include <fstream>

DataParser::DataParser() {

}

template<>
void DataParser::createVariable<CHAR>(DataSection& dataSection, const std::string& name, const std::string& value) const {
	CharVector values = getArrayFromLiteral(value);

	dataSection.declareVariableOfType<CHAR>(name, values);
}

DataSection DataParser::parse(std::ifstream& fileStream) {
	DataSection dataSection;

	std::string line;

	while (line != SymbolTable::DataSectionHeader) {
		std::getline(fileStream, line);
	}

	std::getline(fileStream, line);
	while (line != SymbolTable::CodeSectionHeader) {
		if (line.empty()) { std::getline(fileStream, line); continue; }//ignore empty lines

		StringVector tokens = ParserUtilities::split(line);
		std::string name = tokens[1];
		bool isArray = ParserUtilities::isVariableAnArray(name);

		std::string value;
		if (tokens.size() > 3) {
			value = tokens[3];
		}
		else {
			value = "";
		}

		if (isArray) {
			name.erase(name.end() - 3, name.end());
		}
		
		switch (tokens[0][0])
		{
			case 'C':
			case 'c': createVariable<CHAR>(dataSection,name, value); break;
			
			case 'B':
			case 'b': createVariable<BYTE>(dataSection,name, value); break;
			
			case 'w':
			case 'W': createVariable<WORD>(dataSection, name, value); break;
			
			case 'd':
			case 'D': createVariable<DWORD>(dataSection, name, value); break;

			case 'q':
			case 'Q': createVariable<QWORD>(dataSection,name, value); break;
		}
		std::getline(fileStream, line);
	}

	return dataSection;
}

CharVector DataParser::getArrayFromLiteral(const std::string& values) const {
	std::vector<CHAR> res;
	std::for_each(values.begin() + 1, values.end() - 1, [&res](char ch) {res.push_back(ch); });

	return res;
}

template<typename T>
std::vector<T> DataParser::getArrayFromLiteral(const StringVector& values) const {
	std::vector<T> res;
	for (auto iter = values.cbegin(); iter != values.cend(); ++iter) {
		res.push_back(static_cast<T>(std::stol(*iter)));
	}

	return res;
}

template<typename T>
void DataParser::createVariable(DataSection& dataSection,const std::string& name, const std::string& value) const{
	StringVector numbers = ParserUtilities::split(value, ',');
	std::vector<T> values = getArrayFromLiteral<T>(numbers);

	dataSection.declareVariableOfType<T>(name, values);
}
