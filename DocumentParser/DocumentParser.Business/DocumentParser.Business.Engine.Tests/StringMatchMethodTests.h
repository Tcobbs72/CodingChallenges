#pragma once

#include "gtest/gtest.h"

#include <memory>

#include "DocumentParser/DocumentParser.Infrastructure/NamespaceAliases.h"
#include "DocumentParser/DocumentParser.Infrastructure/Defines.h"
#include "DocumentParser/DocumentParser.Infrastructure/Document.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/StringMatchMethod.h"

namespace DocumentParser { namespace Business { namespace Engine { namespace Tests {
	class StringMatchMethodTests : public ::testing::Test
	{
		protected:
			std::shared_ptr<DPBE::StringMatchMethod> _searchMethod;
			DPI::Document* GenerateDocument(std::string name, std::string content);
			std::string GenerateRandomString();

		public:
			StringMatchMethodTests() {}
			~StringMatchMethodTests() {}
			void SetUp();
			void TearDown();
	};
}}}}