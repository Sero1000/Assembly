#include "Compiler.h"

#include "../Frontend/DataSection.h"
#include "../Frontend/DataParser.h"

Compiler::Compiler():dataParser_(new DataParser())
{

}

void Compiler::compile(std::ifstream& fileStream) {
	DataSection dataSection = dataParser_->parse(fileStream);

	std::ofstream outputfile("a.out.asm", std::ios_base::binary | std::ios_base::out);

	write(outputfile, dataSection.Data());
}

void Compiler::write(std::ofstream& outputFile,const ByteVector& byteVector) const {
	for (const auto& byte : byteVector) {
		outputFile << byte;
	}
}