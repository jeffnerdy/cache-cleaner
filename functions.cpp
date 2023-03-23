#include "functions.h"

// comments inside functions are for debugging

bool SetUp(std::string search, std::string clean)
{
	const std::filesystem::directory_entry sentry(search);
	const std::filesystem::directory_entry centry(clean);

	if (sentry.exists() && centry.exists())
	{
		return true;
	}

	return false;
}

bool IsEmpty(std::ifstream& file)
{
	return file.peek() == std::ifstream::traits_type::eof();
}

int SearchDirectory(const std::string& path, std::ofstream& file)
{
	int count{ 0 };
	const std::filesystem::directory_entry directory(path);

	if (directory.exists())
	{
		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			//std::cout << "searching directory: " << path << " :" << std::endl;
			try {
				if (entry.is_directory())
				{
					if ((entry.path().string().find("cache") != std::string::npos) || (entry.path().string().find("Cache") != std::string::npos))
					{
						//std::cout << "found directory: " << entry.path().string() << std::endl;
						file << entry.path().string() << "\n";
						count++;
					}
					else {
						count += SearchDirectory(entry.path().string(), file);
					}
				}
			}
			catch (const std::filesystem::filesystem_error& e) {
				//std::cerr << "caught filesystem error: " << e.what() << std::endl;
			}
			catch (const std::exception& e) {
				//std::cerr << "caught exception while processing path: " << path << ": " << e.what() << std::endl;
			}
		}
	}
	else {
		std::cerr << "error: directory does not exist: " << path << std::endl;
	}

	return count;
}

int RemoveFromDirectory(const std::string& path)
{
	int count{ 0 };
	const std::filesystem::directory_entry directory(path);

	if (directory.exists())
	{
		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			try {
				std::filesystem::remove_all(entry.path());
				count++;
			}
			catch (const std::filesystem::filesystem_error& e) {
				//std::cerr << "caught filesystem error: " << e.what() << std::endl;
			}
			catch (const std::exception& e) {
				//std::cerr << "caught exception while processing path: " << path << ": " << e.what() << std::endl;
			}
		}
	}
	else {
		std::cerr << "error: directory does not exist: " << path << std::endl;
	}

	return count;
}

bool Search(std::string& path, std::ifstream& ifile, std::ofstream& ofile)
{
	int count{ 0 };

	if (IsEmpty(ifile))
	{
		std::cout << "error: no paths have been specified (to_be_searched.txt)" << std::endl;
		Sleep(4000);

		return false;
	}

	while (std::getline(ifile, path))
	{
		count += SearchDirectory(path, ofile);
	}

	std::cout << count << " directorie(s) have been found." << std::endl;
	Sleep(4000);

	return true;
}

bool Clean(std::string& path, std::ifstream& file)
{
	int count{ 0 };

	if (IsEmpty(file))
	{
		std::cout << "error: no paths have been specified (to_be_cleaned.txt)" << std::endl;
		Sleep(4000);

		return false;
	}

	while (std::getline(file, path))
	{
		count += RemoveFromDirectory(path);
	}

	std::cout << count << " file(s) have been removed." << std::endl;

	return true;
}
