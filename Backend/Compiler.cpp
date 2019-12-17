#include "Compiler.h"

#include "../Frontend/DataSection.h"
#include "../Frontend/DataParser.h"
#include "../Frontend/CodeSection.h"
#include "../Frontend/CodeParser.h"

Compiler::Compiler()
	:stackParser_(std::make_unique<StackParser>())
	,dataParser_(std::make_unique<DataParser>())
	,codeParser_(std::make_unique<CodeParser>())
	,mainParser_(std::make_unique<MainParser>())
{

}

void Compiler::compile(std::ifstream& fileStream) {
	StackSection stackSection = stackParser_->parse(fileStream);
	DataSection dataSection = dataParser_->parse(fileStream);
	CodeSection codeSection = codeParser_->parse(fileStream,dataSection);
	MainSection mainSection = mainParser_->parse(fileStream,codeSection);

	std::fstream outputfile("out.asm", std::ios_base::binary | std::ios_base::out);

	outputfile << stackSection << dataSection << codeSection << mainSection;
}

void Compiler::write(std::ofstream& outputFile,const ByteVector& byteVector) const {
	for (const auto& byte : byteVector) {
		outputFile << byte;
	}
}