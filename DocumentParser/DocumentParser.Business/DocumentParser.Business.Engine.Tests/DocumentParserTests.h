#pragma once

#include "gtest/gtest.h"

#include "DocumentParser/DocumentParser.Infrastructure/NamespaceAliases.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/DocumentParser.h"

namespace DocumentParser { namespace Business { namespace Mocks { class MockConfigLoader; }}}
namespace DocumentParser { namespace Business { namespace Mocks { class MockDocumentLoader; }}}

namespace DocumentParser { namespace Business { namespace Engine { namespace Tests {
	class DocumentParserTests : public ::testing::Test
	{
		protected:
			DPBM::MockConfigLoader* _configLoader;
			DPBM::MockDocumentLoader* _documentLoader;
			DPBE::DocumentParserController* _documentParser;

		public:
			DocumentParserTests() {}
			~DocumentParserTests() {}
			void SetUp();
			void TearDown();
	};
}}}}