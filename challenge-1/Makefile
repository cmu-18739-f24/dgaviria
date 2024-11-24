# Makefile to compile a C program with 32-bit architecture and no stack protection

CC = gcc
CFLAGS = -fno-stack-protector -fno-stack-check -g
SRC = p1vuln.c
OUT = p1vuln

# Default target
all: $(OUT)

# Rule to compile and link the program
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Clean target to remove generated files
clean:
	rm -f $(OUT)

