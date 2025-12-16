#ifndef VERHOEFF_H
#define VERHOEFF_H

#include <string>

/**
 * @brief Verhoeff Algorithm Implementation
 * 
 * The Verhoeff algorithm is a checksum formula for error detection developed by the Dutch mathematician Jacobus Verhoeff and was first published in 1969.
 * It was the first decimal check digit algorithm which detects all single-digit errors, and all transposition errors involving two adjacent digits.
 */
class Verhoeff {
public:
    /**
     * @brief Validates a number string using the Verhoeff algorithm.
     * 
     * @param num The number string to validate (e.g., "1234567890").
     * @return true If the checksum is valid.
     * @return false If the checksum is invalid.
     */
    static bool validate(const std::string& num);

    /**
     * @brief Generates the Verhoeff checksum digit for a given number string.
     * 
     * @param num The number string to generate the checksum for.
     * @return int The checksum digit (0-9).
     */
    static int generateChecksum(const std::string& num);

    /**
     * @brief Appends the generated checksum to the number string.
     * 
     * @param num The number string.
     * @return std::string The number string with the checksum appended.
     */
    static std::string generateVerhoeff(const std::string& num);

private:
    // The multiplication table
    static const int d[10][10];
    
    // The permutation table
    static const int p[8][10];
    
    // The inverse table
    static const int inv[10];
};

#endif // VERHOEFF_H
