#include "bf.h"
#include <stdio.h>
#include <stdlib.h>
#include "comma_input.h"
#include "stack.h"

#define BF_SIZE 30000

static void greater_than(size_t *index) {
    if (*index >= BF_SIZE - 1) {
        fprintf(stderr, "\nError: Range error.\n");
        exit(EXIT_FAILURE);
    }

    (*index)++;
}

static void less_than(size_t *index) {
    if (*index <= 0) {
        fprintf(stderr, "\nError: Range error.\n");
        exit(EXIT_FAILURE);
    }

    (*index)--;
}

static void plus(unsigned char *bf, size_t index) {
    bf[index]++;
}

static void minus(unsigned char *bf, size_t index) {
    bf[index]--;
}

static void dot(const unsigned char *bf, size_t index) {
    printf("%c", bf[index]);
}

static void comma(unsigned char *bf, size_t index, size_t comma_counter) {
    bf[index] = next_comma_input(comma_counter);
}

static void open_bracket(size_t current_pos) {
    push(current_pos);
}

static void close_bracket(const unsigned char *bf, size_t index, size_t *i) {
    if (bf[index] == 0) {
        pop();
    } else {
        *i = peek();
    }
}

static void execute_command(char c, size_t *i, size_t comma_counter) {
    static unsigned char bf[BF_SIZE] = {0};
    static size_t index = 0;

    switch (c) {
        case '>': greater_than(&index); break;
        case '<': less_than(&index); break;
        case '+': plus(bf, index); break;
        case '-': minus(bf, index); break;
        case '.': dot(bf, index); break;
        case ',': comma(bf, index, comma_counter); break;
        case '[': open_bracket(*i); break;
        case ']': close_bracket(bf, index, i); break;
    }
}

void run_bf_code(const char *code, size_t comma_counter) {
    printf("Output:\n");

    for (size_t i = 0; code[i] != '\0'; i++) {
        execute_command(code[i], &i, comma_counter);
    }

    if (!is_empty()) {
        fprintf(stderr, "Error: Unbalanced brackets - %d unmatched '['.\n", size());
        exit(EXIT_FAILURE);
    }

    printf("\n");
}
