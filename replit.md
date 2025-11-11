# C++ Console Application

## Overview
This is a simple C++ console application that demonstrates unsigned integer types in C++. The program displays the size (in bytes) of different unsigned integer types: `unsigned short`, `unsigned int`, `unsigned long`, and `unsigned long long`.

## Project Setup
- **Language**: C++ (C++03 standard)
- **Build System**: Makefile with g++ compiler
- **Type**: Console application

## Project Structure
```
.
├── main.cpp       # Main C++ source file
├── Makefile       # Build configuration
└── .gitignore     # Git ignore rules for C++ projects
```

## Build & Run
The project uses a Makefile for building:
- `make clean` - Removes compiled files and executables
- `make` - Compiles the source code
- `./main` - Runs the compiled executable

The workflow is configured to automatically clean, build, and run the program.

## Compiler Settings
- Compiler: g++ (GNU C++ Compiler)
- Standard: C++03 (`-std=c++03`)
- Flags: `-Wall -g` (all warnings, debug info)

## Recent Changes
- **2025-11-11**: Project imported and set up for Replit environment
  - Verified C++ toolchain (cpp-clang14) installation
  - Configured build workflow: `make clean && make && ./main`
  - Successfully compiled and executed the program
  - Program demonstrates unsigned integer type sizes
