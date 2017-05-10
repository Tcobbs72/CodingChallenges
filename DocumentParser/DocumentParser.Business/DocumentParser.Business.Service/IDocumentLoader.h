#pragma once

#include <vector>
#include "DocumentParser/DocumentParser.Infrastructure/NamespaceAliases.h"

namespace DocumentParser { namespace Business { namespace Service {
	class IDocumentLoader
	{
	public:
		virtual ~IDocumentLoader() {}
		virtual std::vector<DPI::Document> LoadDocuments() = 0;
	};
}}}