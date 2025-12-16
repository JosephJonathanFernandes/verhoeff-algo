# Verhoeff Algorithm Implementation

This repository contains a C++ implementation of the **Verhoeff Algorithm**, a checksum formula for error detection developed by Jacobus Verhoeff in 1969.

## Overview

The Verhoeff algorithm is designed to detect all single-digit errors and all transposition errors involving two adjacent digits. It uses the properties of the Dihedral Group $D_5$.

### Key Components
1.  **Multiplication Table ($d$)**: Based on the Cayley table of the Dihedral group $D_5$.
2.  **Permutation Table ($p$)**: Applies a permutation based on the position of the digit.
3.  **Inverse Table ($inv$)**: Used to find the multiplicative inverse of a digit.

## Project Structure

```
verhoeff-algo/
├── src/
│   └── verhoeff.cpp       # Implementation of the algorithm
├── include/
│   └── verhoeff.h         # Header file with class definition
├── examples/
│   └── main.cpp           # Example usage and interactive demo
├── tests/
│   └── test_verhoeff.cpp  # Unit tests
├── .github/
│   └── workflows/         # CI configuration
├── CMakeLists.txt         # Build configuration
├── LICENSE                # MIT License
└── README.md              # Documentation
```

## How to Build

You can build this project using CMake.

### Prerequisites
*   CMake (version 3.10 or higher)
*   C++ Compiler (GCC, Clang, MSVC)

### Build Steps

1.  Create a build directory:
    ```bash
    mkdir build
    cd build
    ```

2.  Generate build files:
    ```bash
    cmake ..
    ```

3.  Build the project:
    ```bash
    cmake --build .
    ```

## Running Tests

To run the unit tests:

```bash
cd build
ctest
# Or run the test executable directly:
# ./run_tests
```

## Usage

After building, you can run the example executable:

```bash
./verhoeff_example
# On Windows:
# .\Debug\verhoeff_example.exe
```

### Code Example

```cpp
#include "verhoeff.h"
#include <iostream>

int main() {
    std::string number = "12345";
    
    // Generate checksum
    std::string withChecksum = Verhoeff::generateVerhoeff(number);
    std::cout << "Generated: " << withChecksum << std::endl; // Output: 123451 (example)
    
    // Validate
    bool isValid = Verhoeff::validate(withChecksum);
    std::cout << "Is Valid: " << (isValid ? "Yes" : "No") << std::endl;
    
    return 0;
}
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
