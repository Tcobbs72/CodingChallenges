#include "gtest/gtest.h"
#include "DocumentParser/DocumentParser.Infrastructure/NamespaceAliases.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/SearchMethodFactory.h"

TEST(SearchMethodFactoryTests, SampleTest)
{
	DPBE::SearchMethodFactory factory;
	factory.GenerateSearchMethod(0);
	factory.GenerateSearchMethod(1);
	factory.GenerateSearchMethod(2);
	factory.GenerateSearchMethod(3);
	ASSERT_TRUE(true);
}