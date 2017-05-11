#include <memory>
#include <iostream>
#include <string>
#include <unistd.h>

#include "DocumentParser/DocumentParser.Infrastructure/NamespaceAliases.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/DocumentParser.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/IConfigLoader.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/ConfigLoader.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/IDocumentLoader.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/DocumentLoader.h"

int main(int argc, char** argv)
{
	char cCurrentPath[256];
	if(!getcwd(cCurrentPath, sizeof(cCurrentPath)))
	{
		std::cout << "Failed to get current directory\n";
		return 1;
	}
	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0';
	std::string documentPath = std::string(cCurrentPath) + "/sample_text/";

	DPBS::IConfigLoader* configLoader = new DPBS::ConfigLoader();
	DPBS::IDocumentLoader* documentLoader = new DPBS::DocumentLoader(documentPath);

	auto parser = DPBE::DocumentParserController(configLoader);
	parser.ParseDocuments(documentLoader);

	delete configLoader;
	delete documentLoader; 

	return 0;
}