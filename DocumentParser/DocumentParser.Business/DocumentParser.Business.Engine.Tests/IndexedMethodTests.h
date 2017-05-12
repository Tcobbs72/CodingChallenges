#pragma once

#include "gtest/gtest.h"

#include <memory>

#include "DocumentParser/DocumentParser.Infrastructure/NamespaceAliases.h"
#include "DocumentParser/DocumentParser.Infrastructure/Defines.h"
#include "DocumentParser/DocumentParser.Infrastructure/Document.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/IndexedMethod.h"

namespace DocumentParser { namespace Business { namespace Engine { namespace Tests {
	class IndexedMethodTests : public ::testing::Test
	{
		protected:
			std::shared_ptr<DPBE::IndexedMethod> _searchMethod;
			DPI::Document* GenerateDocument(std::string name, std::string content);
			std::string GenerateRandomString();

		public:
			IndexedMethodTests() {}
			~IndexedMethodTests() {}
			void SetUp();
			void TearDown();
	};
}}}}