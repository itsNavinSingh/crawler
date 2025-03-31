# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I./src -I/usr/include/libxml2

# Libraries
LIBS = -lxml2 -lcurl

# Directories
SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

# Source files (including main.cpp inside src/)
SRCS = $(wildcard $(SRC_DIR)/*/*.cpp) $(SRC_DIR)/main.cpp
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Executable name
TARGET = $(BIN_DIR)/crawler

# Default rule
all: $(TARGET)

# Compile source files into object files
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files into the final executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

# Run the program
run: all
	./$(TARGET)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)
