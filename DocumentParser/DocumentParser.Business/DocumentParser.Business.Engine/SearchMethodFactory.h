#pragma once

#include <memory>
#include <stdexcept>
#include "DocumentParser/DocumentParser.Infrastructure/NamespaceAliases.h"
#include "DocumentParser/DocumentParser.Infrastructure/Defines.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/StringMatchMethod.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/RegExMethod.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/IndexedMethod.h"

namespace DocumentParser { namespace Business { namespace Engine { 
	static std::shared_ptr<DPBE::ISearchMethod> GenerateSearchMethod(DPI::SearchMethod searchMethodType)
	{
		std::shared_ptr<DPBE::ISearchMethod> searchMethod;
		switch(searchMethodType)
		{
			case DPI::StringMatch:
				searchMethod = std::shared_ptr<DPBE::StringMatchMethod>(new DPBE::StringMatchMethod());
				break;
			case DPI::RegEx:
				searchMethod = std::shared_ptr<DPBE::RegExMethod>(new DPBE::RegExMethod());
				break;
			case DPI::Indexed:
				searchMethod = std::shared_ptr<DPBE::IndexedMethod>(new DPBE::IndexedMethod());
				break;
			default:
				throw std::invalid_argument("Invalid search method type received");
		};
		return searchMethod;
	}
}}}