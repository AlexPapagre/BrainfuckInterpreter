CC = gcc
CFLAGS = -Wall -Wextra

SRC_DIR = src
OBJ_DIR = build

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

TARGET = bf

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)
	@echo "Built $(TARGET) executable"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< -> $@"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(TARGET) $(OBJ_DIR)
	@echo "Cleaned $(TARGET) executable"
	@echo "Cleaned $(OBJ_DIR) directory"
