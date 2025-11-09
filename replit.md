# C++ Console Application

## Overview
This is a simple C++ console application that demonstrates basic C++ program structure. The program outputs "Test" to the console.

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
- **2025-11-08**: Project imported and set up for Replit environment
  - Installed C++ toolchain (cpp-clang14)
  - Configured build workflow
  - Verified successful compilation and execution
