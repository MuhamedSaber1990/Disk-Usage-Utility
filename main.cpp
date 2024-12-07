#include "command_line.h"
#include "disk_usage.h"
#include <memory>

int main(int argc, char *argv[]) {
  std::unique_ptr<std::string> path;
  handle_command_line(argc, argv, path);
  show_disk_usage(*path);
  return 0;
}