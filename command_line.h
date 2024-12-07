#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

#include <memory>
#include <string>

void print_help();
void handle_command_line(int argc, char *argv[],
                         std::unique_ptr<std::string> &path);

#endif
