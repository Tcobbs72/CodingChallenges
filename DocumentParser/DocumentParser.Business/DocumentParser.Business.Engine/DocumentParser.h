#pragma once

#include <memory>

#include "DocumentParser/DocumentParser.Infrastructure/NamespaceAliases.h"
#include "DocumentParser/DocumentParser.Infrastructure/Defines.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/ISearchMethod.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/IConfigLoader.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/IDocumentLoader.h"

namespace DocumentParser { namespace Business { namespace Engine {
	class DocumentParserController
	{
	private:
		std::shared_ptr<DPBE::ISearchMethod> _searchMethod;
		DPI::Configurations _configs;

	public:
		DocumentParserController(DPBS::IConfigLoader* configLoader);
		~DocumentParserController();
		void ParseDocuments(DPBS::IDocumentLoader* documentLoader);
	};
}}}