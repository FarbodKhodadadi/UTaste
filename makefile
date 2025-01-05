# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -I./data -I./exeption -I./general -I./src -MMD -MP

# Directories
SRC_DIR = src
DATA_DIR = data
DIS_DIR=discount
EXCEPTION_DIR = exeption
GENERAL_DIR = general
BUILD_DIR = build


# Output
TARGET = UTaste

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(DATA_DIR)/*.cpp) \
            $(wildcard $(EXCEPTION_DIR)/*.cpp) $(wildcard $(GENERAL_DIR)/*.cpp) $(wildcard $(DIS_DIR)/*.cpp)

# Object files and dependency files
OBJ_FILES = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(notdir $(SRC_FILES)))
DEP_FILES = $(OBJ_FILES:.o=.d)

# Default target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^
	rm -rf $(BUILD_DIR)
# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(DATA_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(DIS_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(EXCEPTION_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(GENERAL_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure the build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

 
# Clean rule
clean:
	rm -rf $(TARGET) $(BUILD_DIR)

# Run target
run: $(TARGET)
	./$(TARGET)

# Include dependency files
-include $(DEP_FILES)

# Phony targets
.PHONY: all clean run
