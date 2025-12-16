cmake_minimum_required(VERSION 3.10)
project(VerhoeffAlgorithm VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directory
include_directories(include)

# Create a library for the algorithm
add_library(verhoeff src/verhoeff.cpp)

# Create the executable
add_executable(verhoeff_example examples/main.cpp)

# Link the library to the executable
target_link_libraries(verhoeff_example verhoeff)

# Testing
enable_testing()
add_executable(run_tests tests/test_verhoeff.cpp)
target_link_libraries(run_tests verhoeff)
add_test(NAME VerhoeffTests COMMAND run_tests)

