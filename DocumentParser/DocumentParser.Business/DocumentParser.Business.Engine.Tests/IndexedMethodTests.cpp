#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine.Tests/IndexedMethodTests.h"

#include <stdlib.h>
#include <time.h>

using DocumentParser::Business::Engine::Tests::IndexedMethodTests;

void IndexedMethodTests::SetUp()
{
	this->_searchMethod = std::shared_ptr<DPBE::IndexedMethod>(new DPBE::IndexedMethod());
	std::string content = "test document. this document has minimal content. the reason is because i want to keep it on 1 line!";
	std::string name = "Test.txt";
	DPI::Document* document = this->GenerateDocument(name, content);
	this->_searchMethod->Initialize(document);
	delete document;
}

void IndexedMethodTests::TearDown()
{
}

DPI::Document* IndexedMethodTests::GenerateDocument(std::string name, std::string content)
{
	DPI::Document* document = new DPI::Document(name);
	document->AddLine(content);
	return document;
}

TEST_F(IndexedMethodTests, InitializeSetsOccurenceMap)
{
	std::string content = "test document. this document has minimal content. the reason is because i want to keep it on 1 line!";
	EXPECT_TRUE(this->_searchMethod->GetOccurenceMap().size() > 0);
}

TEST_F(IndexedMethodTests, ReturnsZeroIfEmptyFile)
{
	std::string searchString = "test";
	std::string content = "";
	std::string name = "Test.txt";
	DPI::Document* document = this->GenerateDocument(name, content);
	this->_searchMethod->Initialize(document);
	EXPECT_EQ(this->_searchMethod->FindOccurences(searchString), 0);
	delete document;
}

TEST_F(IndexedMethodTests, ReturnsZeroIfNotFound)
{
	std::string searchString = "abc";
	EXPECT_EQ(this->_searchMethod->FindOccurences(searchString), 0);
}

TEST_F(IndexedMethodTests, ReturnsOccurencesIfWordFound)
{
	std::string searchString = "test";
	EXPECT_EQ(this->_searchMethod->FindOccurences(searchString), 1);
}

TEST_F(IndexedMethodTests, ReturnsMultipleOccurencesIfWordFound)
{
	std::string searchString = "document";
	EXPECT_EQ(this->_searchMethod->FindOccurences(searchString), 2);
}

TEST_F(IndexedMethodTests, ReturnsOccurencesIfPhraseFound)
{
	std::string searchString = "ment. t";
	EXPECT_EQ(this->_searchMethod->FindOccurences(searchString), 1);
}

TEST_F(IndexedMethodTests, ReturnsMultipleOccurencesIfPhraseFound)
{
	std::string searchString = "ent. t";
	EXPECT_EQ(this->_searchMethod->FindOccurences(searchString), 2);
}

TEST_F(IndexedMethodTests, ReturnsOccurencesForNumbers)
{
	std::string searchString = "1";
	EXPECT_EQ(this->_searchMethod->FindOccurences(searchString), 1);
}

TEST_F(IndexedMethodTests, ReturnsOccurencesForSpecialCharacters)
{
	std::string searchString = "!";
	EXPECT_EQ(this->_searchMethod->FindOccurences(searchString), 1);
}

std::string IndexedMethodTests::GenerateRandomString() 
{
    static const char alphanum[] =
    	" ~!@#$^&*()-+_=[]{}|/,.<>?`;:"
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    srand(time(NULL));

    std::string randomString;
    int length = rand() % 14 + 1; // random length between 1 and 15
    for (int i = 0; i < length; ++i) {
        randomString += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return randomString;
}

TEST_F(IndexedMethodTests, PerformanceTest10Million)
{
	std::string content = 
		"test document. this document has more content. the reason is because i want to test performance! "
		"To do so i am writing a longer document to parse through in hopes to gain a greater understanding "
		"of which search method is fastest. I grew up in Eagan, MN which is a suburb of St. Paul. While "
		"attending high school I had no idea what I wanted to do but I knew that I liked numbers and science. "
		"With that knowledge I applied to a couple schools and ended up choosing Iowa State University because "
		"of it well-known engineering department and the beautiful campus. During my freshman year I attended "
		"a course that brought in a different type of engineer and eventually decided to follow the path of "
		"Computer Engineering. After my first year I found that I did not carry as much passion for hardware "
		"as I did for software so I changed my major to Software Engineering. I attained some great experience "
		"through multiple internships and during my senior year I received multiple offers for full-time "
		"employment. It was an incredibly hard decision but ended up choosing to work at Belvedere Trading in "
		"Chicago despite not knowing anyone in Chicago and not understanding much about trading. It was scary "
		"but ended up being the one of the best decisions I have made. I am now moving back to Minneapolis due "
		"to some external forces but appreciate everything that Chicago and Belvedere has done for me.";
	std::string name = "Test.txt";
	DPI::Document* document = this->GenerateDocument(name, content);
	this->_searchMethod->Initialize(document);
	delete document;

	const int trials = 10000000;
	for(int i = 0; i < trials; i++)
	{
		std::string searchString = this->GenerateRandomString();
		this->_searchMethod->FindOccurences(searchString);
	}
}

TEST_F(IndexedMethodTests, PerformanceTest2Million)
{
	std::string content = 
		"test document. this document has more content. the reason is because i want to test performance! "
		"To do so i am writing a longer document to parse through in hopes to gain a greater understanding "
		"of which search method is fastest. I grew up in Eagan, MN which is a suburb of St. Paul. While "
		"attending high school I had no idea what I wanted to do but I knew that I liked numbers and science. "
		"With that knowledge I applied to a couple schools and ended up choosing Iowa State University because "
		"of it well-known engineering department and the beautiful campus. During my freshman year I attended "
		"a course that brought in a different type of engineer and eventually decided to follow the path of "
		"Computer Engineering. After my first year I found that I did not carry as much passion for hardware "
		"as I did for software so I changed my major to Software Engineering. I attained some great experience "
		"through multiple internships and during my senior year I received multiple offers for full-time "
		"employment. It was an incredibly hard decision but ended up choosing to work at Belvedere Trading in "
		"Chicago despite not knowing anyone in Chicago and not understanding much about trading. It was scary "
		"but ended up being the one of the best decisions I have made. I am now moving back to Minneapolis due "
		"to some external forces but appreciate everything that Chicago and Belvedere has done for me.";
	std::string name = "Test.txt";
	DPI::Document* document = this->GenerateDocument(name, content);
	this->_searchMethod->Initialize(document);
	delete document;

	const int trials = 2000000;
	for(int i = 0; i < trials; i++)
	{
		std::string searchString = this->GenerateRandomString();
		this->_searchMethod->FindOccurences(searchString);
	}
}

TEST_F(IndexedMethodTests, PerformanceTest10Thousand)
{
	std::string content = 
		"test document. this document has more content. the reason is because i want to test performance! "
		"To do so i am writing a longer document to parse through in hopes to gain a greater understanding "
		"of which search method is fastest. I grew up in Eagan, MN which is a suburb of St. Paul. While "
		"attending high school I had no idea what I wanted to do but I knew that I liked numbers and science. "
		"With that knowledge I applied to a couple schools and ended up choosing Iowa State University because "
		"of it well-known engineering department and the beautiful campus. During my freshman year I attended "
		"a course that brought in a different type of engineer and eventually decided to follow the path of "
		"Computer Engineering. After my first year I found that I did not carry as much passion for hardware "
		"as I did for software so I changed my major to Software Engineering. I attained some great experience "
		"through multiple internships and during my senior year I received multiple offers for full-time "
		"employment. It was an incredibly hard decision but ended up choosing to work at Belvedere Trading in "
		"Chicago despite not knowing anyone in Chicago and not understanding much about trading. It was scary "
		"but ended up being the one of the best decisions I have made. I am now moving back to Minneapolis due "
		"to some external forces but appreciate everything that Chicago and Belvedere has done for me.";
	std::string name = "Test.txt";
	DPI::Document* document = this->GenerateDocument(name, content);
	this->_searchMethod->Initialize(document);
	delete document;

	const int trials = 10000;
	for(int i = 0; i < trials; i++)
	{
		std::string searchString = this->GenerateRandomString();
		this->_searchMethod->FindOccurences(searchString);
	}
}