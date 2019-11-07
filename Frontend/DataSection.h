#ifndef DATASECTION_H
#define DATASECTION_H

#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

#include "TypeDefs.h"

class DataSection {
public:
	DataSection();

	DataSection(const DataSection& other) = default;
	DataSection& operator=(const DataSection& other) = default;

	DataSection(DataSection&& other) = default;
	DataSection& operator=(DataSection&& other) = default;

	template<typename T>
	void declareVariableOfType(const std::string& name, std::vector<T>& values);

	const ByteVector& Data() const { return data_; }

private:
	template<typename T>
	void writeInData(int index, std::vector<T>& value);

private:
	std::unordered_map<std::string, int> namesAndAdresses_;
	ByteVector data_;
};

using DataSectionUPtr = std::unique_ptr<DataSection>;
using DataSectionSPtr = std::shared_ptr<DataSection>;
using DataSectionWPtr = std::weak_ptr<DataSection>;

template<typename T>
void DataSection::declareVariableOfType(const std::string& name, std::vector<T>& values) {
	int address = data_.size();
	data_.resize(data_.size() + sizeof(T) * values.size());
	
	writeInData(address, values);

	namesAndAdresses_.insert(std::make_pair(name, address));
}

template<typename T>
void DataSection::writeInData(int index, std::vector<T>& values) {
	for (int i = 0; i < values.size(); ++i) {
		BYTE* byte = &data_[index];
		T* valuePtr = reinterpret_cast<T*>(byte);

		*valuePtr = values[i];

		index += sizeof(T);
	}
}

#endif