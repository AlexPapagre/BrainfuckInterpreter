#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BF_SIZE 30000
#define INITIAL_BUFFER_CAPACITY 128

char *add(size_t *size, size_t *capacity, char *buffer, char c, int *comma_counter) {
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

void bf(char c, size_t *i, char *comma_inputs) {
    static unsigned char bf[BF_SIZE] = {0};
    static size_t index = 0;
    static size_t comma_index = 0;

    switch (c) {
        case '>':
            if (index == BF_SIZE - 1) {
                fprintf(stderr, "RANGE ERROR\n");
                exit(EXIT_FAILURE);
            }

            index++;
            break;
        case '<':
            if (index == 0) {
                fprintf(stderr, "RANGE ERROR\n");
                exit(EXIT_FAILURE);
            }

            index--;
            break;
        case '+':
            bf[index]++;
            break;
        case '-':
            bf[index]--;
            break;
        case '.':
            printf("%c", bf[index]);
            break;
        case ',':
            bf[index] = comma_inputs[comma_index++];
            break;
        case '[':
            // TODO: push from stack
            break;
        case ']':
            if (bf[index] == 0) {
                // TODO: pop from stack
            } else {
                // TODO: peek from stack
            }
            break;
    }
}

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

    if (argc < 2) {
        printf("Input: (Press enter after an emtpy row to stop input):\n");

        char line[1024];
        while (fgets(line, sizeof(line), stdin) != NULL) {
            if (strcmp(line, "\n") == 0) {
                break;
            }

            for (size_t i = 0; i < strlen(line); i++) {
                buffer = add(&size, &capacity, buffer, line[i], &comma_counter);
            }
        }
    } else {
        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("Error opening file.\n");
            exit(EXIT_FAILURE);
        }

        printf("Input:\n");

        int c;
        while ((c = fgetc(file)) != EOF) {
            printf("%c", c);
            buffer = add(&size, &capacity, buffer, c, &comma_counter);
        }

        fclose(file);
    }
    printf("\n\n");

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

    if (size == 0) {
        fprintf(stderr, "No commands found.\n");
        exit(EXIT_FAILURE);
    }

    printf("Clean input (commands only):\n%s\n\n", buffer);

    char *comma_inputs;

    if (comma_counter > 0) {
        comma_inputs = malloc(comma_counter);
        if (comma_inputs == NULL) {
            perror("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }

        printf("\nProvide %d character%s of input (for ',' commands):\n", comma_counter, (comma_counter == 1 ? "" : "s"));

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
                printf("\nProvide %d more character%s of input (for ',' commands):\n", commas_left, (commas_left == 1 ? "" : "s"));
            }
        }
        printf("\n\n");
    }

    printf("Output:\n");

    for (size_t i = 0; i < size; i++) {
        bf(buffer[i], &i, comma_inputs);
    }
    printf("\n");

    if (comma_counter > 0) {
        free(comma_inputs);
    }
    free(buffer);

    return 0;
}
