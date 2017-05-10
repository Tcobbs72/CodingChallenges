#pragma once

#include <vector>
#include "DocumentParser/DocumentParser.Infrastructure/NamespaceAliases.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/IDocumentLoader.h"

namespace DocumentParser { namespace Business { namespace Service {
	class DocumentLoader : public IDocumentLoader
	{
	public:
		DocumentLoader();
		~DocumentLoader();
		std::vector<DPI::Document> LoadDocuments();
	};
}}}