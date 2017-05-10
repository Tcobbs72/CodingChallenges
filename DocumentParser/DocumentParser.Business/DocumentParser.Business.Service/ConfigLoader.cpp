#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/ConfigLoader.h"

#include <iostream>

#include "DocumentParser/DocumentParser.Infrastructure/Translations.h"

using DocumentParser::Business::Service::ConfigLoader;

ConfigLoader::ConfigLoader()
{
}

ConfigLoader::~ConfigLoader()
{
}

bool ConfigLoader::TryGetSearchString(std::string& searchString)
{
	std::cout << "Enter the search term: ";
	getline(std::cin, searchString);

	return searchString.empty() == false;
}

bool ConfigLoader::TryGetSearchMethod(DPI::SearchMethod& searchMethod)
{
	int searchMethodInt;
	std::cout << "Search Method: 1) String Match 2) Regular Expression 3) Indexed" << std::endl;
	std::cin >> searchMethodInt;

	if(std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		return false;
	}

	try
	{
		searchMethod = DPI::TranslateIntToSearchMethod(searchMethodInt);
		return true;
	}
	catch(std::invalid_argument e)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		return false;
	}
}

DPI::Configurations ConfigLoader::LoadConfigurations()
{
	std::string searchString;
	while(this->TryGetSearchString(searchString) == false)
	{
		std::cout << "Invalid search term. Must not be empty." << std::endl;
	}

	DPI::SearchMethod searchMethod;
	while(this->TryGetSearchMethod(searchMethod) == false)
	{
		std::cout << "Invalid search method. Options are 1) String Match 2) Regular Expression 3) Indexed" << std::endl;
	}

	DPI::Configurations configurations;
	configurations.searchString = searchString;
	configurations.searchMethod = searchMethod;
	return configurations;
}