#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string fileName;
    std::string word;
    int wordCount = 0;

    // Prompt the user for the file name
    std::cout << "Please enter the file name: ";
    std::cin >> fileName;

    // Open the file
    std::ifstream inputFile(fileName);

    // Check if the file opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return 1;
    }

    // Read words from the file and count them
    while (inputFile >> word) {
        wordCount++;
    }

    // Display the word count
    std::cout << "Total word count: " << wordCount << std::endl;

    // Close the file
    inputFile.close();

    return 0;
}
