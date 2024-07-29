#include "ColorCodePrinter.h"
#include <iomanip>
#include <iostream>
namespace TelCoColorCoder
{
    #define FORMAT std::setw(18) << std::setfill(' ')
    void PrintColorCodeRefManual()
    {
        std::cout << "----------|---------------------|----------------------" << std::endl;
        std::cout << " Code     |      Major Color    |     Minor Color    " << std::endl;
        std::cout << "----------|---------------------|----------------------" << std::endl;
        int numberOfCodes = numberOfMajorColors * numberOfMinorColors;
        for (auto colorIndex = 1; colorIndex <= numberOfCodes; ++colorIndex)
        {
            ColorPair clrPair = GetColorFromPairNumber(colorIndex);
            std::string majorColor = MajorColorNames[clrPair.getMajor()];
            std::string minorColor = MinorColorNames[clrPair.getMinor()];
            if (colorIndex % numberOfMinorColors != 0)
            {
                majorColor = std::string("");
            }
            std::cout << "  " << std::left << FORMAT << colorIndex << FORMAT << majorColor << FORMAT << minorColor << std::endl;
            if(!majorColor.empty())
            {
                std::cout << "-------------------------------------------------------" << std::endl;
            }
        }
    }
}