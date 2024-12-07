#include "command_line.h"
#include <Windows.h>
#include <cstring>
#include <iostream>

void print_help() {
  std::cout << "Usage: disk_usage [OPTIONS] [PATH]\n"
            << "Show disk usage information.\n\n"
            << "Options:\n"
            << "  --help   Show this help message\n"
            << "  --list   List all available drives (Windows only)\n\n"
            << "If no arguments are given, the program will list drives and "
               "prompt for input.\n";
}

void list_drives() {
  DWORD drives = GetLogicalDrives();
  std::cout << "Available drives:\n";

  for (char letter = 'A'; letter <= 'Z'; ++letter) {
    if (drives & (1 << (letter - 'A'))) {
      std::cout << letter << ":\\\n";
    }
  }
}

void handle_command_line(int argc, char *argv[],
                         std::unique_ptr<std::string> &path) {
  if (argc > 1) {
    if (std::strcmp(argv[1], "--help") == 0) {
      print_help();
      exit(0);
    } else if (std::strcmp(argv[1], "--list") == 0) {
      list_drives();
      exit(0);
    } else {
      path = std::make_unique<std::string>(argv[1]);
    }
  } else {
    list_drives();
    std::cout
        << "Please enter the drive letter you want to check (e.g., C:\\): ";
    std::string drive;
    std::cin >> drive;
    path = std::make_unique<std::string>(drive);
  }
}
