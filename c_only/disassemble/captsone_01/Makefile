# Compiler
CXX = g++

# Compiler and linker flags
# debug flags are -xc++ -E -v -
CXXFLAGS = -O3 -Wall -I../inc 
LDLIBS = -lcapstone -lbfd -liberty -lz

# Automatically find all .cc files under src/
SRC := $(wildcard *.cc ../inc/*.cc)
OBJ := $(SRC:.cc=.o)

# Name of the final executable
BIN = basic_caplinear

# Default target
all: $(BIN)

# Link the object files into the binary
$(BIN): $(OBJ)
	$(CXX) $(OBJ) $(LDLIBS) -o $@

# Compile .cc files to .o files
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJ) $(BIN)
