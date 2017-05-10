#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/RegExMethod.h"

#include <iostream>

using DocumentParser::Business::Engine::RegExMethod;

RegExMethod::RegExMethod()
{
	std::cout << "CREATING REGEX\n";
}

RegExMethod::~RegExMethod()
{
}

bool RegExMethod::TryGetNextOccurence(int& out)
{
	return false;
}