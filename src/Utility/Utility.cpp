#include "Utility.h"

#include <iostream>
#include <fstream>
#include <string>

namespace Utility {
    // Function to read text from file
    std::string FileText(std::string FilePath) {
        // Define file stream variable
        std::ifstream File;
        //Open the file
        File.open(FilePath, std::ios::in);
        //Check if file is open
        if (File.is_open()) {
            std::string text = std::string((std::istreambuf_iterator<char>(File)), std::istreambuf_iterator<char>());
            File.close();
            return text;
        }
        else {
            std::cout << "Failed to open file: " << FilePath << std::endl;
            return "";
        }
    }
}