# Compiler options
CC = gcc
CFLAGS = -Wall -Wextra -g

# Directories
SRC_DIR = src
BIN_DIR = bin
DOC_DIR = doc
SAVE_DIR = save

# Source files (in src directory)
SRC = $(wildcard $(SRC_DIR)/*.c)
HEAD = $(wildcard $(SRC_DIR)/*.h)
OBJ = $(subst $(SRC_DIR), $(BIN_DIR), $(SRC:.c=.o))

# Executable name
EXEC = $(BIN_DIR)/myprogram

# Remove command
RM = rm -f
RMDIR = rm -rf

# Copy command
CP = cp -r

# Targets
.PHONY: all clean doxy save

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(EXEC) $(SAVE_DIR)/* Doxyfile
	$(RMDIR) $(DOC_DIR)/*

# Generate Doxyfile and then run doxygen
doxy: $(DOC_DIR)/Doxyfile
	cd $(DOC_DIR) && doxygen Doxyfile

$(DOC_DIR)/Doxyfile:
	doxygen -g $(DOC_DIR)/Doxyfile
	sed -i 's|^OUTPUT_DIRECTORY.*|OUTPUT_DIRECTORY = $(abspath $(DOC_DIR))|' $(DOC_DIR)/Doxyfile
	echo "INPUT = $(abspath $(SRC_DIR))" >> $(DOC_DIR)/Doxyfile

# Save source files
save:
	$(CP) $(SRC_DIR)/*.[ch] $(SAVE_DIR)