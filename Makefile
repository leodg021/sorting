CC := gcc
CFLAGS := -Wall -Wextra 

BIN_DIR := ./bin
BUILD_DIR := ./build
SRC_DIR := ./src

INC_DIR := ./include
INC_FLAGS := -I $(INC_DIR)

TARGET_EXEC := $(BIN_DIR)/main

SRCS := $(shell find $(SRC_DIR) -name '*.c')
INCS := $(INC_DIR)/sorts.h #$(INC_DIR)/%.h
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))


all: $(OBJS) 
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $(TARGET_EXEC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET_EXEC)

