# Compiler and flags
CC = gcc
CFLAGS = -Wall -g
LDFLAGS =

# Directories
SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/menu.c $(SRC_DIR)/text.c $(SRC_DIR)/util.c
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Executable name
EXEC = $(BIN_DIR)/menu_program.exe

# Ensure necessary directories exist
$(OBJ_DIR) $(BIN_DIR):
	@mkdir -p $@

# Default target
all: $(EXEC)

# Compile the source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files to create the executable
$(EXEC): $(OBJS) | $(BIN_DIR)
	$(CC) $(OBJS) $(LDFLAGS) -o $(EXEC)

# Clean object files and executable
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Run the program (Explicitly mention .exe for Windows)
run: $(EXEC)
	@$(EXEC)

.PHONY: all clean run
