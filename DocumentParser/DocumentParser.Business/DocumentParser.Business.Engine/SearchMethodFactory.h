#pragma once

#include <memory>
#include "DocumentParser/DocumentParser.Infrastructure/NamespaceAliases.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/StringMatchMethod.h"

namespace DocumentParser { namespace Business { namespace Engine { 
	class SearchMethodFactory
	{
	public:
		SearchMethodFactory() {}
		~SearchMethodFactory() {}
		std::unique_ptr<DPBE::ISearchMethod> GenerateSearchMethod(int searchMethod)
		{
			switch(searchMethod)
			{
				case 1:
					std::cout << "Creating String Match Method\n";
					break;
				case 2:
					std::cout << "Creating RegEx Search Method\n";
					break;
				case 3:
					std::cout << "Creating Indexed Search Method\n";
					break;
				default:
					std::cout << "Unknown Search Method\n";
					break;
			};
			return std::unique_ptr<DPBE::StringMatchMethod>();
		}
	};
}}}