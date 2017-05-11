#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/DocumentParser.h"

#include <iostream>
#include <string>

#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/SearchMethodFactory.h"
#include "DocumentParser/DocumentParser.Infrastructure/Document.h"

using DocumentParser::Business::Engine::DocumentParserController;

DocumentParserController::DocumentParserController(DPBS::IConfigLoader* configLoader)
{
	_configs = configLoader->LoadConfigurations();
	_searchMethod = DPBE::GenerateSearchMethod(_configs.searchMethod);
}

DocumentParserController::~DocumentParserController()
{
}

void DocumentParserController::ParseDocuments(DPBS::IDocumentLoader* documentLoader)
{
	for(const auto& document : documentLoader->GetDocuments())
	{
		_searchMethod->Initialize(document);
		int occurences = _searchMethod->FindOccurences(_configs.searchString);
		std::cout << document->GetName() << " " << occurences << std::endl;
	}
}