#pragma once

#include <unordered_map>
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/ISearchMethod.h"

namespace DocumentParser { namespace Business { namespace Engine {
	class IndexedMethod : public ISearchMethod
	{
	private:
		std::unordered_map<std::string, int> _occurenceMap;
	public:
		IndexedMethod();
		~IndexedMethod();
		void Initialize(DPI::Document* const document);
		int FindOccurences(const std::string& searchString);
	};
}}}