#include "functions.h"

std::string _search = "to_be_searched.txt";
std::string clean = "to_be_cleaned.txt";
std::string path;

int input = 0;

int main()
{
	// set up
	if (!SetUp(_search, clean))
	{
		std::cout << "eroor: missing files." << std::endl;
		Sleep(4000);

		return 0;
	}

	// main logic
	std::cout << "Select an option:\n\n";
	std::cout << "1. Search\n2. Clean\n\n";
	std::cin >> input;
	std::cout << "\n";

	switch (input)
	{
	case 1:
	{
		std::ifstream search("to_be_searched.txt");
		std::ofstream oclean("to_be_cleaned.txt", std::ios_base::app);
		Search(path, search, oclean);
		break;
	}
	case 2:
	{
		std::ifstream iclean("to_be_cleaned.txt");
		Clean(path, iclean);

		std::ofstream clearfile("to_be_cleaned.txt"); // empties to_be_cleaned.txt
		Sleep(4000);
		break;
	}
	}

	return 0;
}
