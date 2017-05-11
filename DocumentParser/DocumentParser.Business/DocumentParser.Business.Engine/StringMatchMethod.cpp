#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/StringMatchMethod.h"

#include <iostream>
#include <algorithm>

using DocumentParser::Business::Engine::StringMatchMethod;

StringMatchMethod::StringMatchMethod()
{
}

StringMatchMethod::~StringMatchMethod()
{
}

void StringMatchMethod::Initialize(DPI::Document* const document)
{
	this->_content = std::string(document->GetContent());
}

int StringMatchMethod::FindOccurences(const std::string& searchString)
{
	int occurences = 0;

	std::size_t pos = this->_content.find( searchString );
    std::size_t initialPos = 0;

    while( pos != std::string::npos ) 
    {
        occurences += 1;
        initialPos = pos + 1;
        pos = this->_content.find( searchString, initialPos );
    }

	return occurences;
}
