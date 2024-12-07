#include "disk_usage.h"
#include <filesystem>
#include <iostream>

DiskUsage::DiskUsage(const std::string &path)
    : path_(path),
      space_info_(std::make_unique<std::filesystem::space_info>()) {
  if (!std::filesystem::exists(path_)) {
    std::cerr << "Error: The specified drive or path \"" << path_
              << "\" does not exist or is not accessible." << std::endl;
    exit(1); 
  }

  try {
    *space_info_ = std::filesystem::space(path_);
  } catch (const std::filesystem::filesystem_error &e) {
    std::cerr << "Error getting disk usage: " << e.what() << std::endl;
    exit(1); 
  }
}

void DiskUsage::print_usage() {
  // Convert bytes to GB
  constexpr uint64_t GB = 1024 * 1024 * 1024;

  double capacity_gb = static_cast<double>(space_info_->capacity) / GB;
  double free_gb = static_cast<double>(space_info_->free) / GB;
  double used_gb = capacity_gb - free_gb;
  double available_gb = static_cast<double>(space_info_->available) / GB;

  std::cout << "Disk usage for path: " << path_ << std::endl;
  std::cout << "Capacity:  " << capacity_gb << " GB" << std::endl;
  std::cout << "Used:      " << used_gb << " GB" << std::endl;
  std::cout << "Available: " << available_gb << " GB" << std::endl;
}

void show_disk_usage(const std::string &path) {
  DiskUsage du(path);
  du.print_usage();
}
