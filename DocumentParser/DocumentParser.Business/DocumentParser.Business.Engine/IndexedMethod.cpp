#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/IndexedMethod.h"

#include <iostream>

using DocumentParser::Business::Engine::IndexedMethod;

IndexedMethod::IndexedMethod()
{
	std::cout << "CREATING INDEXED\n";
}

IndexedMethod::~IndexedMethod()
{
}

bool IndexedMethod::TryGetNextOccurence(int& out)
{
	return false;
}