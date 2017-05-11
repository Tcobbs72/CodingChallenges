#pragma once

#include <vector>
#include <string>
#include <dirent.h>

#include "DocumentParser/DocumentParser.Infrastructure/NamespaceAliases.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/IDocumentLoader.h"

namespace DocumentParser { namespace Business { namespace Service {
	class DocumentLoader : public IDocumentLoader
	{
	private:
		std::vector<DPI::Document*> _documents;
		void TryAddDocument(std::string directory, struct dirent* ent);
		int IsDirectory(const char* path);

	public:
		DocumentLoader(std::string directory);
		~DocumentLoader();
		inline std::vector<DPI::Document*> GetDocuments() { return this->_documents; }
	};
}}}