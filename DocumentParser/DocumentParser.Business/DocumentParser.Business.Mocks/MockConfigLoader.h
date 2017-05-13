#pragma once

#include "gmock/gmock.h"

#include "DocumentParser/DocumentParser.Infrastructure/Defines.h"
#include "DocumentParser/DocumentParser.Infrastructure/NamespaceAliases.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/IConfigLoader.h"

namespace DocumentParser { namespace Business { namespace Mocks {
	class MockConfigLoader : public DPBS::IConfigLoader 
	{
	 public:
	  ~MockConfigLoader() {}

	  MOCK_METHOD0(LoadConfigurations, DPI::Configurations());
	};

}}}