#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/StringMatchMethod.h"

#include <iostream>

using DocumentParser::Business::Engine::StringMatchMethod;

StringMatchMethod::StringMatchMethod()
{
	std::cout << "CREATING STRING MATCH\n";
}

StringMatchMethod::~StringMatchMethod()
{
}

bool StringMatchMethod::TryGetNextOccurence(int& out)
{
	return false;
}