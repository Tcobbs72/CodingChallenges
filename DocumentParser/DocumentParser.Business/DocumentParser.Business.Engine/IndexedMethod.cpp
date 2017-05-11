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
	std::string content = std::string(document->GetContent());
	for(auto start = content.begin(); start != content.end(); ++start)
	{
		for(auto end = start; end != content.end(); ++end)
		{
			if(end != start)
			{
				std::string key = std::string(start, end);
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
}

int IndexedMethod::FindOccurences(const std::string& searchString)
{
	return this->_occurenceMap.find(searchString) == this->_occurenceMap.end() ? 0 : this->_occurenceMap[searchString];
}