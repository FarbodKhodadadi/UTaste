# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -I./data -I./exeption -I./general -I./src

# Directories
SRC_DIR = src
DATA_DIR = data
EXCEPTION_DIR = exeption
GENERAL_DIR = general

# Output
TARGET = main

# Source files
SRC_FILES = $(SRC_DIR)/main.cpp $(SRC_DIR)/command.cpp $(SRC_DIR)/districts.cpp $(SRC_DIR)/restaurant.cpp $(SRC_DIR)/user.cpp
DATA_FILES = $(DATA_DIR)/data.cpp
GENERAL_FILES = $(GENERAL_DIR)/utility.cpp
EXCEPTION_FILES = $(EXCEPTION_DIR)/exception.cpp

# Object files
OBJ_FILES = $(SRC_FILES:.cpp=.o) $(DATA_FILES:.cpp=.o) $(GENERAL_FILES:.cpp=.o) $(EXCEPTION_FILES:.cpp=.o)

# Rule to build the target
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ_FILES)
	rm -f $(OBJ_FILES)
# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
# Clean rule
clean:
	rm -f $(TARGET)
	

# Phony targets
.PHONY: clean
