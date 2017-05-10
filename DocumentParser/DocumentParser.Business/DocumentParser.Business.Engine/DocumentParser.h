#pragma once

#include "DocumentParser/DocumentParser.Infrastructure/NamespaceAliases.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/ISearchMethod.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/IConfigLoader.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/IDocumentLoader.h"

namespace DocumentParser { namespace Business { namespace Engine {
	class DocumentParserController
	{
	private:
		DPBS::IConfigLoader* _configLoader;
		DPBS::IDocumentLoader* _documentLoader;

		void Initialize();

	public:
		DocumentParserController(DPBS::IConfigLoader* configLoader, DPBS::IDocumentLoader* documentLoader);
		~DocumentParserController();
		void Run();
	};
}}}