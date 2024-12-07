# Disk Usage Utility

This is a simple command-line tool that displays disk usage information for a given drive or path. The tool shows the total capacity, used space, and available space on the specified filesystem.

## Features

- **List available drives (on Windows)**: If no path is provided, the program lists all logical drives available on the system.
- **Display disk usage**: Given a valid path, it shows:
  - Capacity
  - Used space
  - Available space
- **Help & Command options**:
  - `--help`: Shows usage instructions.
  - `--list`: Lists all available drives on Windows systems.

## Requirements

- **Operating System**: Primarily Windows (because it uses `GetLogicalDrives`), but can be adapted for other platforms.
- **Compiler**: A C++17-compatible compiler (e.g., `g++` or `clang++`).
- **Standard Library**: Requires C++17 standard library support (for `<filesystem>`).

## Building the Program

1. Make sure you have a C++17 capable compiler installed.
2. Navigate to the directory containing the source code and the `Makefile`.
3. Run `make` to compile the program. For example:
   ```sh
   make
