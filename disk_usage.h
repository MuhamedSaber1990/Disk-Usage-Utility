#ifndef DISK_USAGE_H
#define DISK_USAGE_H

#include <filesystem>
#include <memory>
#include <string>

class DiskUsage {
public:
  DiskUsage(const std::string &path); // Constructor declaration
  void print_usage();

private:
  std::string path_;
  std::unique_ptr<std::filesystem::space_info> space_info_;
};

void show_disk_usage(const std::string &path);

#endif