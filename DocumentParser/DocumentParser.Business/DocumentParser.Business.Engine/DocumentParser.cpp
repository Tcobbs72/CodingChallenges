#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/DocumentParser.h"

#include <iostream>
#include <string>

#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/SearchMethodFactory.h"
#include "DocumentParser/DocumentParser.Infrastructure/Document.h"
#include "DocumentParser/DocumentParser.Infrastructure/Defines.h"

using DocumentParser::Business::Engine::DocumentParserController;

DocumentParserController::DocumentParserController(DPBS::IConfigLoader* configLoader, DPBS::IDocumentLoader* documentLoader)
{
	_configLoader = configLoader;
	_documentLoader = documentLoader;
	this->Initialize();
}

DocumentParserController::~DocumentParserController()
{
}

void DocumentParserController::Initialize()
{
	DPI::Configurations configs = _configLoader->LoadConfigurations();
	std::vector<DPI::Document> documents = _documentLoader->LoadDocuments();

	auto searchMethod = DPBE::GenerateSearchMethod(configs.searchMethod);
}

void DocumentParserController::Run()
{
	std::cout << "RUNNING!!!" << std::endl;
}