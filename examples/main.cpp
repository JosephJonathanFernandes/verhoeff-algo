#include <iostream>
#include <string>
#include "verhoeff.h"

int main() {
    std::cout << "Verhoeff Algorithm Example" << std::endl;
    std::cout << "==========================" << std::endl;

    // Example 1: Validate a number
    std::string validNum = "236"; // 23 + checksum 6
    std::cout << "Validating " << validNum << ": " << (Verhoeff::validate(validNum) ? "Valid" : "Invalid") << std::endl;

    std::string invalidNum = "237";
    std::cout << "Validating " << invalidNum << ": " << (Verhoeff::validate(invalidNum) ? "Valid" : "Invalid") << std::endl;

    // Example 2: Generate a checksum
    std::string rawNum = "23";
    int checksum = Verhoeff::generateChecksum(rawNum);
    std::cout << "Checksum for " << rawNum << " is: " << checksum << std::endl;

    // Example 3: Generate full Verhoeff number
    std::string fullNum = Verhoeff::generateVerhoeff(rawNum);
    std::cout << "Full Verhoeff number for " << rawNum << " is: " << fullNum << std::endl;

    // Interactive mode
    std::cout << "\nEnter a number to validate (or 'q' to quit): ";
    std::string input;
    while (std::cin >> input && input != "q") {
        if (Verhoeff::validate(input)) {
            std::cout << "VALID" << std::endl;
        } else {
            std::cout << "INVALID" << std::endl;
            // Try to suggest what it should be if the last digit was the checksum
            if (input.length() > 1) {
                std::string base = input.substr(0, input.length() - 1);
                std::cout << "Did you mean: " << Verhoeff::generateVerhoeff(base) << "?" << std::endl;
            }
        }
        std::cout << "\nEnter a number to validate (or 'q' to quit): ";
    }

    return 0;
}
