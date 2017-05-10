#include <memory>

#include "DocumentParser/DocumentParser.Infrastructure/NamespaceAliases.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/DocumentParser.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/IConfigLoader.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/ConfigLoader.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/IDocumentLoader.h"
#include "DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/DocumentLoader.h"

int main(int argc, char** argv)
{
	// std::string searchTerm;
	// std::cout << "Enter the search term: ";
	// getline(std::cin, searchTerm);

	// if(searchTerm.empty())
	// {
	// 	std::cout << "Invalid search term. Must not be empty." << std::endl;
	// 	return 1;
	// }

	// int searchMethod;
	// std::cout << "Search Method: 1) String Match 2) Regular Expression 3) Indexed" << std::endl;
	// std::cin >> searchMethod;

	// if(std::cin.fail())
	// {
	// 	std::cin.clear();
	// 	std::cout << "Invalid search method. Options are 1) String Match 2) Regular Expression 3) Indexed" << std::endl;
	// 	return 1;
	// }

	// std::cout << "You chose: " << searchTerm << " " << searchMethod << std::endl;

	DPBS::IConfigLoader* configLoader = new DPBS::ConfigLoader();
	DPBS::IDocumentLoader* documentLoader = new DPBS::DocumentLoader();

	auto parser = DPBE::DocumentParserController(configLoader, documentLoader);
	parser.Run();

	delete configLoader;
	delete documentLoader; 
	
	return 0;
}