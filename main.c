#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "bf.h"

#define INITIAL_BUFFER_CAPACITY 128

int main(int argc, char *argv[]) {
    if (argc > 2) {
        fprintf(stderr, "Usage 1: %s\n", argv[0]);
        fprintf(stderr, "Usage 2: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    size_t size = 0;
    size_t capacity = INITIAL_BUFFER_CAPACITY;

    char *buffer = malloc(capacity);
    if (buffer == NULL) {
        perror("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    int comma_counter = 0;

    buffer = (argc < 2) ? user_input(&size, &capacity, buffer, &comma_counter) : file_input(argv[1], &size, &capacity, buffer, &comma_counter);
    printf("\n\n");

    add_null_terminator(size, capacity, buffer);

    if (size == 0) {
        fprintf(stderr, "No commands found.\n");
        exit(EXIT_FAILURE);
    }

    printf("Clean input (commands only):\n");
    printf("%s\n\n", buffer);

    char *comma_inputs = comma_input(comma_counter);

    printf("Output:\n");

    for (size_t i = 0; i < size; i++) {
        execute_command(buffer[i], &i, comma_inputs);
    }
    printf("\n");

    if (!is_empty()) {
        fprintf(stderr, "UNBALANCED BRACKETS\n");
        exit(EXIT_FAILURE);
    }

    if (comma_counter > 0) {
        free(comma_inputs);
    }
    free(buffer);

    return 0;
}
