#include "verhoeff.h"
#include <iostream>
#include <cassert>
#include <vector>

void test_validation() {
    std::cout << "Running validation tests..." << std::endl;
    
    // Known valid Verhoeff numbers
    assert(Verhoeff::validate("236") == true);
    assert(Verhoeff::validate("123451") == true); 
    assert(Verhoeff::validate("1428570") == true);

    // Known invalid numbers
    assert(Verhoeff::validate("237") == false);
    assert(Verhoeff::validate("123450") == false);
    assert(Verhoeff::validate("12345") == false); // Too short/missing checksum usually fails check
    
    std::cout << "Validation tests passed!" << std::endl;
}

void test_generation() {
    std::cout << "Running generation tests..." << std::endl;

    // Checksum generation
    assert(Verhoeff::generateChecksum("23") == 6);
    assert(Verhoeff::generateChecksum("12345") == 1);
    
    // Full number generation
    assert(Verhoeff::generateVerhoeff("23") == "236");
    assert(Verhoeff::generateVerhoeff("12345") == "123451");

    std::cout << "Generation tests passed!" << std::endl;
}

void test_error_handling() {
    std::cout << "Running error handling tests..." << std::endl;
    
    // Non-digit characters
    assert(Verhoeff::validate("12a45") == false);
    assert(Verhoeff::generateChecksum("12a45") == -1);
    assert(Verhoeff::generateVerhoeff("12a45") == "");

    std::cout << "Error handling tests passed!" << std::endl;
}

int main() {
    test_validation();
    test_generation();
    test_error_handling();
    
    std::cout << "\nAll tests passed successfully!" << std::endl;
    return 0;
}
