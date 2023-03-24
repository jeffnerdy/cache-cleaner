#include "functions.h"

int main()
{
	// set up
	const std::filesystem::path _search = "to_be_searched.txt";
	const std::filesystem::path _clean = "to_be_cleaned.txt";

	if (!SetUp(_search, _clean))
	{
		std::cout << "eroor: missing files." << std::endl;
		Sleep(3000);

		return 0;
	}

	// main logic
	int input{ 0 };
	std::string path;

	std::cout << "Select an option:\n\n";
	std::cout << "1. Search\n2. Clean\n\n";
	std::cin >> input;
	std::cout << "\n";

	switch (input)
	{
	case 1:
	{
		std::ifstream search(_search);
		std::ofstream oclean(_clean, std::ios_base::app);

		Search(path, search, oclean);
		break;
	}
	case 2:
	{
		std::ifstream iclean(_clean);

		Clean(path, iclean);

		std::ofstream clearfile(_clean); // empties to_be_cleaned.txt

		Sleep(3000);
		break;
	}
	}

	return 0;
}
