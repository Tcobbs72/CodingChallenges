#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine.Tests/DocumentParserTests.h"

#include <gmock/gmock.h>

#include "DocumentParser/DocumentParser.Infrastructure/Defines.h"
#include "DocumentParser/DocumentParser.Infrastructure/Document.h"
#include "DocumentParser/DocumentParser.Infrastructure/Translations.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Mocks/MockConfigLoader.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Mocks/MockDocumentLoader.h"

using testing::Return;
using testing::_;

using DocumentParser::Business::Engine::Tests::DocumentParserTests;

void DocumentParserTests::SetUp()
{
	this->_configLoader = new DPBM::MockConfigLoader();
	DPI::Configurations configs = DPI::Configurations();
	configs.searchMethod = DPI::TranslateIntToSearchMethod(1);
	configs.searchString = std::string("Some search");
	EXPECT_CALL(*(this->_configLoader), LoadConfigurations()).Times(1).WillOnce(Return(configs));
	
	this->_documentLoader = new DPBM::MockDocumentLoader();
	this->_documentParser = new DPBE::DocumentParserController(this->_configLoader);
}

void DocumentParserTests::TearDown()
{
	delete this->_configLoader;
	delete this->_documentLoader;
	delete this->_documentParser;
}

TEST_F(DocumentParserTests, ParseDocumentsGetsDocumentsFromLoader)
{
	auto document1 = new DPI::Document(std::string("some_file.txt"));
	document1->AddLine(std::string("I am document 1."));

	auto document2 = new DPI::Document(std::string("some_file.txt"));
	document2->AddLine(std::string("I am document 1."));

	std::vector<DPI::Document*> documents;
	documents.push_back(document1);
	documents.push_back(document2);

	EXPECT_CALL(*(this->_documentLoader), GetDocuments()).Times(1).WillOnce(Return(documents));

	this->_documentParser->ParseDocuments(this->_documentLoader);

	delete document1;
	delete document2;
}