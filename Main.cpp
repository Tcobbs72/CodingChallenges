#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	std::string searchTerm;
	std::cout << "Enter the search term: ";
	getline(std::cin, searchTerm);

	if(searchTerm.empty())
	{
		std::cout << "Invalid search term. Must not be empty." << std::endl;
		return 1;
	}

	int searchMethod;
	std::cout << "Search Method: 1) String Match 2) Regular Expression 3) Indexed" << std::endl;
	std::cin >> searchMethod;

	if(std::cin.fail())
	{
		std::cin.clear();
		std::cout << "Invalid search method. Options are 1) String Match 2) Regular Expression 3) Indexed" << std::endl;
		return 1;
	}

	std::cout << "You chose: " << searchTerm << " " << searchMethod << std::endl;

	return 0;
}