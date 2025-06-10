all: bf

bf: main.c input.c bf.c stack.c
	gcc main.c input.c bf.c stack.c -o bf
	@echo "Build complete: bf created successfully."

clean:
	@rm -f bf *.o
	@echo "Cleaned build files."
