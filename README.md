
## Overview
This project implements the Hamming Code (8,4) in C++, designed to encode a 4-bit binary number into an 8-bit code, which includes error detection and correction capabilities. This system is capable of correcting single-bit errors and detecting double-bit errors, making it highly effective for scenarios where data integrity is critical.

## Project Structure

The project contains the following files:

- **main.cpp**: This file contains the `main` function and handles user input and output.
- **HammingCode.cpp**: Contains the implementation of the Hamming code logic.
- **HammingCode.h**: Includes the declarations of the Hamming code functions used in `HammingCode.cpp`.
- **CMakeLists.txt**: Specifies the build configuration, allowing for portable compilation across different systems.

## Prerequisites

- A C++ compiler that supports C++11 or newer (e.g., GCC, Clang, MSVC).
- CMake version 3.10 or higher for building the project.

## Building the Project

To compile and run this project, follow these steps:

### Clone the Repository

Start by cloning the repository to your local machine:

```bash
git clone <Repository URL>
cd project-directory
```

## Build with CMake
Create a build directory and compile the project:
- mkdir build && cd build
- cmake ..
- make

## Running the Program
Execute the program from the command line:
- ./HammingProgram

## How to Use the Program
1. Input Data Bits: Enter 4 data bits when prompted. Example input should be binary numbers like 1 0 1 1.
2. View Encoded Message: The program will display the 8-bit encoded message.
3. Introduce an Error: Optionally, re-enter the 8-bit encoded message with a deliberate error to test the error correction.
4. View Results: The program will detect and correct any single-bit errors or notify if multiple errors are detected.

## Example Session
- Enter 4 data bits (as 1 0 1 1): 1 0 1 1
- Correctly Formatted Encoded Message: 0 1 1 0 0 1 1 1
- Enter the 8-bit encoded message (you can introduce an error if you like): 1 1 1 0 0 1 1 1
- Error detected at position: 1
- Corrected Encoded Message: 0 1 1 0 0 1 1 1
- Decoded (and corrected) Message: 1 0 1 1

>>>>>>> e02eb28 (Initial commit)
