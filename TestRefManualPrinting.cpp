#include "TestRefManualPrinting.h"
#include "ColorCodePrinter.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <assert.h>

std::string removeNonAlphanumeric(const std::string& input) {
    std::string result = input;
    result.erase(std::remove_if(result.begin(), result.end(), [](char c) {
        return !std::isalnum(static_cast<unsigned char>(c));
    }), result.end());
    return result;
}

void testPrintColorCodeRefManual() 
{
    // Capture the output of the PrintColorCodeRefManual function
    std::ostringstream output;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    TelCoColorCoder::PrintColorCodeRefManual(); //call print ref manual method
    std::cout.rdbuf(oldCoutStreamBuf); // Restore the original cout buffer
    std::string filename = "RefManual.txt"; // Expected output
    std::string expectedOutput = "";
    std::ifstream refManualFile(filename);
    if (refManualFile.is_open()) {
        std::string line = "";
        while (getline(refManualFile, line)) {
            expectedOutput += (line + "\n");
        }
        refManualFile.close();
    }
    std::string capturedOutput = output.str();
    std::string actual = removeNonAlphanumeric(capturedOutput);
    std::string expected = removeNonAlphanumeric(expectedOutput);
    assert(actual == expected); // Assert the output matches the expected output
    std::cout << "Test passed: PrintColorCodeRefManual output is correct." << std::endl; // Print success message
}
