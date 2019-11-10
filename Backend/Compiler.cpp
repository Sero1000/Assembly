#include "Compiler.h"

#include "../Frontend/DataSection.h"
#include "../Frontend/DataParser.h"
#include "../Frontend/CodeSection.h"
#include "../Frontend/CodeParser.h"

Compiler::Compiler():dataParser_(new DataParser()),codeParser_(new CodeParser())
{

}

void Compiler::compile(std::ifstream& fileStream) {
	DataSection dataSection = dataParser_->parse(fileStream);
	CodeSection codeSection = codeParser_->parse(fileStream,dataSection);

	std::ofstream outputfile("out.asm", std::ios_base::binary | std::ios_base::out);

	write(outputfile, dataSection.data());
}

void Compiler::write(std::ofstream& outputFile,const ByteVector& byteVector) const {
	for (const auto& byte : byteVector) {
		outputFile << byte;
	}
}