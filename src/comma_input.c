#include "comma_input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *comma_inputs;
static size_t comma_index = 0;

void get_comma_inputs(size_t comma_counter) {
    if (comma_counter <= 0) {
        comma_inputs = NULL;
        return;
    }

    comma_inputs = malloc(comma_counter);
    if (!comma_inputs) {
        perror("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Comma inputs (Provide %ld character%s for ',' commands):\n", comma_counter, (comma_counter == 1 ? "" : "s"));

    size_t comma_index = 0;
    char line[1024];

    while (comma_index < comma_counter) {
        if (fgets(line, sizeof(line), stdin) == NULL) {
            fprintf(stderr, "Error reading input.\n");
            exit(EXIT_FAILURE);
        }

        for (size_t i = 0; i < strlen(line) && comma_index < (size_t) comma_counter; i++) {
            if (line[i] != '\n') {
                comma_inputs[comma_index++] = line[i];
            }
        }

        if (comma_index < comma_counter) {
            size_t commas_left = comma_counter - comma_index;
            printf("\nComma inputs (Provide %ld more character%s for ',' commands):\n", commas_left, (commas_left == 1 ? "" : "s"));
        }
    }
    printf("\n");
}

char next_comma_input(size_t comma_counter) {
    if (comma_index >= comma_counter) {
        fprintf(stderr, "Runtime error: Comma input not found.\n");
        exit(EXIT_FAILURE);
    }

    return comma_inputs[comma_index++];
}

void free_comma_inputs(size_t comma_counter) {
    if (comma_counter > 0) {
        free(comma_inputs);
    }
}
