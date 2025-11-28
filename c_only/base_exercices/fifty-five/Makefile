# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Output programs
OUTPUT1 = freader
OUTPUT2 = fwriter

# Source files
SRC1 = reader.c
SRC2 = writer.c

# Object files
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

# Default target
all: $(OUTPUT1) $(OUTPUT2)

# Compile prog1
$(OUTPUT1): $(OBJ1)
	$(CC) $(OBJ1) -o $(OUTPUT1)

# Compile prog2
$(OUTPUT2): $(OBJ2)
	$(CC) $(OBJ2) -o $(OUTPUT2)

# Compile 1.c to 1.o
$(OBJ1): $(SRC1)
	$(CC) $(CFLAGS) -c $(SRC1)

# Compile 2.c to 2.o
$(OBJ2): $(SRC2)
	$(CC) $(CFLAGS) -c $(SRC2)

# Clean up
clean:
	rm -f $(OBJ1) $(OBJ2) $(OUTPUT1) $(OUTPUT2)

# .PHONY target to prevent conflicts with filenames
.PHONY: all clean
