# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Target executable
TARGET = disk_usage

# Source files
SRC = main.cpp disk_usage.cpp command_line.cpp

# Object files (will be generated from source files)
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to create the target (disk_usage executable)
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files (object files and executable)
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets (don't correspond to files)
.PHONY: all clean