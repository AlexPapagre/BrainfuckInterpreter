#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *add_command(size_t *size, size_t *capacity, char *buffer, char c, int *comma_counter) {
    if (*size >= *capacity) {
        *capacity *= 2;
        char *tmp_buffer = realloc(buffer, *capacity);
        if (tmp_buffer == NULL) {
            free(buffer);
            perror("Memory reallocation failed.\n");
            exit(EXIT_FAILURE);
        }
        buffer = tmp_buffer;
    }

    if (strchr("><+-.,[]", c)) {
        buffer[(*size)++] = c;
        if (c == ',') {
            (*comma_counter)++;
        }
    }

    return buffer;
}

char *user_input(size_t *size, size_t *capacity, char *buffer, int *comma_counter) {
    printf("Input: (Press enter after an emtpy row to stop input):\n");

    char line[1024];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        if (strcmp(line, "\n") == 0) {
            break;
        }

        size_t length = strlen(line);
        for (size_t i = 0; i < length; i++) {
            buffer = add_command(size, capacity, buffer, line[i], comma_counter);
        }
    }

    return buffer;
}

char *file_input(char *filename, size_t *size, size_t *capacity, char *buffer, int *comma_counter) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Input:\n");

    int c;
    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);
        buffer = add_command(size, capacity, buffer, (char) c, comma_counter);
    }

    fclose(file);

    return buffer;
}

void add_null_terminator(size_t size, size_t capacity, char *buffer) {
    if (size >= capacity) {
        capacity += 1;
        char *tmp_buffer = realloc(buffer, capacity);
        if (tmp_buffer == NULL) {
            perror("Memory reallocation failed.\n");
            exit(EXIT_FAILURE);
        }
        buffer = tmp_buffer;
    }

    buffer[size] = '\0';
}

char *comma_input(int comma_counter) {
    if (comma_counter == 0) {
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
