#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/DocumentLoader.h"

#include "DocumentParser/DocumentParser.Infrastructure/Document.h"

using DocumentParser::Business::Service::DocumentLoader;

DocumentLoader::DocumentLoader()
{
}

DocumentLoader::~DocumentLoader()
{
}

std::vector<DPI::Document> DocumentLoader::LoadDocuments()
{
	std::vector<DPI::Document> documents;
	return documents;
}