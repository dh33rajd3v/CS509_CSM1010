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
    assignment1/src/csr_file.cpp

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