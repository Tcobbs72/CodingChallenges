#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/IndexedMethod.h"

#include <iostream>

using DocumentParser::Business::Engine::IndexedMethod;

IndexedMethod::IndexedMethod()
{
}

IndexedMethod::~IndexedMethod()
{
}

void IndexedMethod::Initialize(DPI::Document* const document)
{
	this->_occurenceMap.clear();

	// reserve worst case n^2 possible phrases
	std::string content = std::string(document->GetContent());
	this->_occurenceMap.reserve(content.length() * content.length());
	for(auto start = content.begin(); start != content.end(); ++start)
	{
		for(auto end = start; end != content.end(); ++end)
		{
			std::string key = std::string(start, end + 1);
			if(this->_occurenceMap.find(key) == this->_occurenceMap.end())
			{
				this->_occurenceMap[key] = 1;
			}
			else
			{
				this->_occurenceMap[key] += 1;
			}
		}
	}
}

int IndexedMethod::FindOccurences(const std::string& searchString)
{
	return this->_occurenceMap.find(searchString) == this->_occurenceMap.end() ? 0 : this->_occurenceMap[searchString];
}