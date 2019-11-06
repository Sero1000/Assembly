#include "ParserUtilities.h"

#include <algorithm>

namespace ParserUtilities {
	using std::string;
	using std::vector;

	StringVector split(const std::string& line, char seperator) {
		string::const_iterator firstIter, secondIter;
		vector<string> result;
		firstIter = secondIter = line.begin();

		while (secondIter != line.end()) {
			secondIter = std::find(firstIter, line.cend(), seperator);
			result.push_back(line.substr(firstIter - line.begin(), secondIter - firstIter));
			if (secondIter != line.cend()) {
				firstIter = secondIter + 1;
			}
		}

		return result;
	}

	bool isVariableAnArray(const std::string& variableName)	{
		int size = variableName.size();
		return variableName[size - 1] == ']' && variableName[size - 3] == '[';
	}

	void trim(std::string& str) {
		str.erase(std::remove_if(str.begin(), str.end(), std::isspace()));
	}
}