# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -O2

# Target executable
TARGET = common_wrapper

# Source files
SRCS = \
    common_wrapper.cpp \
    assignment1/assignment_1_driver.cpp \
    assignment1/src/gemm_blocking.cpp \
    assignment1/src/gemm_simple.cpp \
    csr_file.cpp \
    assignment2/assignment_2_driver.cpp \
    assignment2/src/bf.cpp \
    assignment2/src/fw.cpp 

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(TARGET).exe $(TARGET)

.PHONY: all clean