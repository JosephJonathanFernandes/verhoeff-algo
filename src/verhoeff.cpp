#include "verhoeff.h"
#include <algorithm>
#include <vector>

// The multiplication table based on Dihedral Group D5
const int Verhoeff::d[10][10] = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 2, 3, 4, 0, 6, 7, 8, 9, 5},
    {2, 3, 4, 0, 1, 7, 8, 9, 5, 6},
    {3, 4, 0, 1, 2, 8, 9, 5, 6, 7},
    {4, 0, 1, 2, 3, 9, 5, 6, 7, 8},
    {5, 9, 8, 7, 6, 0, 4, 3, 2, 1},
    {6, 5, 9, 8, 7, 1, 0, 4, 3, 2},
    {7, 6, 5, 9, 8, 2, 1, 0, 4, 3},
    {8, 7, 6, 5, 9, 3, 2, 1, 0, 4},
    {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
};

// The permutation table
const int Verhoeff::p[8][10] = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 5, 7, 6, 2, 8, 3, 0, 9, 4},
    {5, 8, 0, 3, 7, 9, 6, 1, 4, 2},
    {8, 9, 1, 6, 0, 4, 3, 5, 2, 7},
    {9, 4, 5, 3, 1, 2, 6, 8, 7, 0},
    {4, 2, 8, 6, 5, 7, 3, 9, 0, 1},
    {2, 7, 9, 3, 8, 0, 6, 4, 1, 5},
    {7, 0, 4, 6, 9, 1, 3, 2, 5, 8}
};

// The inverse table
const int Verhoeff::inv[10] = {0, 4, 3, 2, 1, 5, 6, 7, 8, 9};

bool Verhoeff::validate(const std::string& num) {
    int c = 0;
    int len = num.length();

    // Iterate from right to left
    for (int i = 0; i < len; i++) {
        int digit = num[len - 1 - i] - '0'; // Get digit from end
        if (digit < 0 || digit > 9) return false; // Invalid character check
        
        // c = d[c][p[i % 8][digit]]
        c = d[c][p[i % 8][digit]];
    }

    return (c == 0);
}

int Verhoeff::generateChecksum(const std::string& num) {
    int c = 0;
    int len = num.length();

    // Iterate from right to left, but start position index at 1 because the checksum will be at position 0
    for (int i = 0; i < len; i++) {
        int digit = num[len - 1 - i] - '0';
        if (digit < 0 || digit > 9) return -1; // Error

        // c = d[c][p[(i + 1) % 8][digit]]
        c = d[c][p[(i + 1) % 8][digit]];
    }

    return inv[c];
}

std::string Verhoeff::generateVerhoeff(const std::string& num) {
    int checksum = generateChecksum(num);
    if (checksum == -1) return ""; // Error
    return num + std::to_string(checksum);
}
