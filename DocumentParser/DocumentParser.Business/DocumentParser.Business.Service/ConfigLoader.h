#pragma once

#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/IConfigLoader.h"

namespace DocumentParser { namespace Business { namespace Service {
	class ConfigLoader : public IConfigLoader
	{
	private:
		bool TryGetSearchString(std::string& searchString);
		bool TryGetSearchMethod(DPI::SearchMethod& searchMethod);

	public:
		ConfigLoader();
		~ConfigLoader();
		DPI::Configurations LoadConfigurations();
	};
}}}