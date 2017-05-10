#pragma once

#include "DocumentParser/DocumentParser.Infrastructure/NamespaceAliases.h"
#include "DocumentParser/DocumentParser.Infrastructure/Defines.h"

namespace DocumentParser { namespace Business { namespace Service {
	class IConfigLoader
	{
	public:
		virtual ~IConfigLoader() {}
		virtual DPI::Configurations LoadConfigurations() = 0;
	};
}}}