#include "DataSection.h"

int DataSection::addressOf(const std::string& name) const {
	return namesAndAdresses_.find(name)->second; 
}

std::fstream& operator<<(std::fstream& file, const DataSection& dataSection) {
	for (auto iter = dataSection.data_.cbegin(); iter != dataSection.data_.cend(); ++iter) {
		file.write(reinterpret_cast<const char*>(&(*iter)), sizeof(*iter));
	}

	return file;
}