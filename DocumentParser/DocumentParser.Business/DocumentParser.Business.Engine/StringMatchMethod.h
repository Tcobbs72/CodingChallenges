#pragma once

#include <vector>
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/ISearchMethod.h"

namespace DocumentParser { namespace Business { namespace Engine {
	class StringMatchMethod : public ISearchMethod
	{
	private:
		std::string _content;
	public:
		StringMatchMethod();
		~StringMatchMethod();
		void Initialize(DPI::Document* const document);
		int FindOccurences(const std::string& searchString);
	};
}}}