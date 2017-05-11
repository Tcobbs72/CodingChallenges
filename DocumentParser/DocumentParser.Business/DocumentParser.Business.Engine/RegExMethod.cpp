#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/RegExMethod.h"

#include <iostream>
#include <regex>

using DocumentParser::Business::Engine::RegExMethod;

RegExMethod::RegExMethod()
{
}

RegExMethod::~RegExMethod()
{
}

void RegExMethod::Initialize(DPI::Document* const document)
{
	this->_content = std::string(document->GetContent());
}

int RegExMethod::FindOccurences(const std::string& searchString)
{
	int occurences = 0;
	std::string regexString = "(?=" + searchString + ")";
	std::regex rgx(regexString.c_str());

	for(auto it = std::cregex_iterator(this->_content.c_str(), this->_content.c_str() + this->_content.length(), rgx); it != std::cregex_iterator(); ++it)
    {
        occurences += 1;
    }

	return occurences;
}