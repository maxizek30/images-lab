#include <iostream>
#include <fstream>

void processHeader();
void processBody();
void Negate();
void Quantize();
void Grayscale();
void Horizontal();

int main()
{
    std::string fileName;
    std::string outputFileName;
    std::string modification;

    std::cout << "Input File: ";
    std::cin >> fileName;

    std::ifstream inputFile(fileName);
    if (!inputFile)
    {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::cout << "Output File: ";
    std::cin >> outputFileName;

    std::ofstream outputFile(outputFileName);
    if (!outputFile)
    {
        std::cerr << "Error creating file!" << std::endl;
        return 1;
    }

    std::cout << "Select modification: ";
    std::cout << "(a) negate ";
    std::cout << "(b) quantize ";
    std::cout << "(c) gray scale ";
    std::cout << "(d) flip horizontal ";

    std::cin >> modification;

    // process header

    if (modification == "a")
    {
        Negate();
    }
    else if (modification == "b")
    {
        Quantize();
    }
    else if (modification == "c")
    {
        Grayscale();
    }
    else if (modification == "d")
    {
        Horizontal();
    }
    else
    {
        std::cerr << "Invalid modification selected!" << std::endl;
        return 1;
    }

    std::cout << fileName << " --> " << outputFileName;
    std::cout << "Complete, closing files." << std::endl;

    return 0;
}
