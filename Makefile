CC = gcc
SRC = src/main.c src/args.c src/comma_input.c src/input.c src/bf.c src/stack.c
OUT = bf
CFLAGS = -Wall -Wextra -O2

all: $(OUT)

$(OUT): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(OUT)
	@echo "Build complete: $(OUT) created successfully."

clean:
	@rm -f $(OUT)
	@echo "Cleaned build files."
