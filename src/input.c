#include "input.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CODE_CAPACITY 128

char *add_command(size_t *size, size_t *capacity, char *code, char c, int *comma_counter) {
    if (*size >= *capacity) {
        *capacity *= 2;
        char *tmp_code = realloc(code, *capacity);
        if (tmp_code == NULL) {
            free(code);
            perror("Memory reallocation failed.\n");
            exit(EXIT_FAILURE);
        }
        code = tmp_code;
    }

    if (strchr("><+-.,[]", c)) {
        code[(*size)++] = c;
        if (c == ',') {
            (*comma_counter)++;
        }
    }

    return code;
}

char *user_input(size_t *size, size_t *capacity, char *code, int *comma_counter) {
    printf("Input: (Press Enter after an emtpy row to stop input):\n");

    char line[1024];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        if (strcmp(line, "\n") == 0) {
            break;
        }

        size_t length = strlen(line);
        for (size_t i = 0; i < length; i++) {
            code = add_command(size, capacity, code, line[i], comma_counter);
        }
    }

    return code;
}

char *file_input(const char *filename, size_t *size, size_t *capacity, char *code, int *comma_counter) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Input:\n");

    int c;
    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);
        code = add_command(size, capacity, code, (char) c, comma_counter);
    }

    fclose(file);

    return code;
}

char *add_null_terminator(size_t size, size_t capacity, char *code) {
    if (size >= capacity) {
        capacity += 1;
        char *tmp_code = realloc(code, capacity);
        if (tmp_code == NULL) {
            perror("Memory reallocation failed.\n");
            exit(EXIT_FAILURE);
        }
        code = tmp_code;
    }
    code[size] = '\0';

    return code;
}

char *read_bf_code(int argc, const char *filename, int *comma_counter) {
    size_t size = 0;
    size_t capacity = INITIAL_CODE_CAPACITY;

    char *code = malloc(capacity);
    if (code == NULL) {
        perror("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    code = (argc < 2) ? user_input(&size, &capacity, code, comma_counter) : file_input(filename, &size, &capacity, code, comma_counter);
    printf("\n\n");

    code = add_null_terminator(size, capacity, code);

    if (size == 0) {
        fprintf(stderr, "Error: No commands found.\n");
        exit(EXIT_FAILURE);
    }

    return code;
}

char *get_comma_inputs(int comma_counter) {
    if (comma_counter <= 0) {
        return NULL;
    }

    char *comma_inputs = malloc(comma_counter);
    if (comma_inputs == NULL) {
        perror("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Comma inputs (Provide %d character%s for ',' commands):\n", comma_counter, (comma_counter == 1 ? "" : "s"));

    size_t comma_index = 0;
    char line[1024];

    while (comma_index < (size_t) comma_counter) {
        if (fgets(line, sizeof(line), stdin) == NULL) {
            fprintf(stderr, "Error reading input.\n");
            exit(EXIT_FAILURE);
        }

        for (size_t i = 0; i < strlen(line) && comma_index < (size_t) comma_counter; i++) {
            if (line[i] != '\n') {
                comma_inputs[comma_index++] = line[i];
            }
        }

        if (comma_index < (size_t) comma_counter) {
            int commas_left = comma_counter - (int) comma_index;
            printf("\nComma inputs (Provide %d more character%s for ',' commands):\n", commas_left, (commas_left == 1 ? "" : "s"));
        }
    }
    printf("\n\n");

    return comma_inputs;
}
