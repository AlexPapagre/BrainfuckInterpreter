all: bf

bf: src/main.c src/args.c src/input.c src/bf.c src/stack.c
	@gcc src/main.c src/args.c src/input.c src/bf.c src/stack.c -o bf
	@echo "Build complete: bf created successfully."

clean:
	@rm -f bf
	@echo "Cleaned build files."
