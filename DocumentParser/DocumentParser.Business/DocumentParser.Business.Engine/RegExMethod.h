#pragma once

#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/ISearchMethod.h"

namespace DocumentParser { namespace Business { namespace Engine {
	class RegExMethod : public ISearchMethod
	{
	private:
		std::string _content;
	public:
		RegExMethod();
		~RegExMethod();
		void Initialize(DPI::Document* const document);
		int FindOccurences(const std::string& searchString);
		inline std::string GetContent() const { return this->_content; }
	};
}}}