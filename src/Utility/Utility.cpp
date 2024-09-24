#include "Utility.h"

#include <fstream>
#include <iostream>
#include <string>

namespace Utility
{
std::string Parser(std::string FilePath)
{                                      // Function to read text from file
	std::ifstream File;                // Define file stream variable
	File.open(FilePath, std::ios::in); // Open the file
	if (File.is_open())
	{ // Check if file is open
		std::string text = std::string((std::istreambuf_iterator<char>(File)), std::istreambuf_iterator<char>());
		File.close();
		return text;
	}
	else
	{
		std::cout << "Failed to open file: " << FilePath << std::endl;
		return "";
	}
}
} // namespace Utility