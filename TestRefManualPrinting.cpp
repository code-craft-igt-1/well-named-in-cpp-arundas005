#include "TestRefManualPrinting.h"
#include "ColorCodePrinter.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <assert.h>

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
    assert(capturedOutput == expectedOutput); // Assert the output matches the expected output
    std::cout << "Test passed: PrintColorCodeRefManual output is correct." << std::endl; // Print success message
}