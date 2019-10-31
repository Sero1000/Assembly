#include "DataParser.h"
#include "ParserUtilities.h"
#include "TypeDefs.h"

#include <string>
#include <fstream>

using std::string;

DataParser::DataParser() {

}

DataSection DataParser::parse(std::ifstream& fileStream) {
	DataSection dataSection;

	string line;

	while (line != ".Data") {
		std::getline(fileStream, line);
	}

	std::getline(fileStream, line);
	while (line != ".CODE" ) {

		StringVector tokens = ParserUtilities::split(line);
		string name = tokens[1];
		bool isArray = ParserUtilities::isVariableAnArray(name);

		string value;
		if (tokens.size() > 3) {
			value = tokens[3];
		}
		else {
			value = "";
		}

		if (isArray) {
			name.erase(name.end() - 3, name.end());
		}

		switch (tokens[0][1])
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

			default: throw ParserException("Invalid Type ");
		}
		std::getline(fileStream, line);
	}

	return dataSection;
}

template<typename T>
void DataParser::createVariable(DataSection& dataSection,const std::string& name, const std::string& value) const{
	StringVector numbers = ParserUtilities::split(value, ',');
	vector<T> values = getArrayFromLiteral<T>(numbers);

	dataSection.declareVariableOfType<T>(name, values);
}

template<>
void DataParser::createVariable<char>(DataSection& dataSection,const std::string& name, const std::string& value) const {
	std::vector<char> values = getArrayFromLiteral<char>(value);

	dataSection.declareVariableOfType<char>(name, values);
}

template<typename T>
std::vector<T> DataParser::getArrayFromLiteral(const std::string& values) const {
	std::vector<T> res;
	for (auto iter = values.cbegin(); iter != values.cend(); ++iter) {
		res.push_back(static_cast<T>(std::stol(*iter)));
	}

	return res;
}

template<>
std::vector<char> DataParser::getArrayFromLiteral<char>(const std::string& values) const {
	std::vector<char> res;
	std::for_each(values.begin(), values.end(), [&res](char ch) {res.push_back(ch); });

	return res;
}