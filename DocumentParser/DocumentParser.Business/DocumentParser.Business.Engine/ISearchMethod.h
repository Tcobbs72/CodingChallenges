#pragma once

#include <string>
#include "DocumentParser/DocumentParser.Infrastructure/Document.h"
#include "DocumentParser/DocumentParser.Infrastructure/NamespaceAliases.h"

namespace DocumentParser { namespace Business { namespace Engine { 
	class ISearchMethod 
	{
	public:
		virtual ~ISearchMethod() {};
		virtual void Initialize(DPI::Document* const document) = 0;
		virtual int FindOccurences(const std::string& searchString) = 0;
	};
}}}