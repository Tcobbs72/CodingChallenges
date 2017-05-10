#include "gtest/gtest.h"
#include "DocumentParser/DocumentParser.Infrastructure/NamespaceAliases.h"
#include "DocumentParser/DocumentParser.Infrastructure/Defines.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/SearchMethodFactory.h"

TEST(SearchMethodFactoryTests, SampleTest)
{
	DPBE::GenerateSearchMethod(DPI::StringMatch);
	DPBE::GenerateSearchMethod(DPI::RegEx);
	DPBE::GenerateSearchMethod(DPI::Indexed);
	ASSERT_TRUE(true);
}