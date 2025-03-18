# Makefile

CC := clang	# Define your compiler of preference.
CFLAGS := -Wall -Wextra 	# Define your preferred compiler flags.

BIN_DIR := ./bin
BUILD_DIR := ./build
SRC_DIR := ./src

INC_DIR := ./include
INC_FLAGS := -I $(INC_DIR)

TARGET_EXEC := $(BIN_DIR)/main

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))


all: $(OBJS) 
	@mkdir -p $(BIN_DIR)
	@echo "===== Generating executable: $(TARGET_EXEC)"
	@$(CC) $(CFLAGS) $^ -o $(TARGET_EXEC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(BUILD_DIR)
	@echo "===== Compiling: $<"
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@


.PHONY: clean
clean:
	@echo "===== Cleaning binary and build files."
	rm -f $(BUILD_DIR)/*.o $(TARGET_EXEC)

