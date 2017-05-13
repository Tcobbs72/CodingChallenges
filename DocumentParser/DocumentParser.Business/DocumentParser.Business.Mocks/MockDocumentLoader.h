#pragma once

#include "gmock/gmock.h"

#include "DocumentParser/DocumentParser.Infrastructure/Document.h"
#include "DocumentParser/DocumentParser.Infrastructure/NamespaceAliases.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/IDocumentLoader.h"

namespace DocumentParser { namespace Business { namespace Mocks {
	class MockDocumentLoader : public DPBS::IDocumentLoader 
	{
	 public:
	  ~MockDocumentLoader() {}

	  MOCK_METHOD0(GetDocuments, std::vector<DPI::Document*>());
	  MOCK_METHOD0(CleanupDocuments, void());
	};

}}}