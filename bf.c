#include <stdio.h>
#include <stdlib.h>
#include "bf.h"
#include "stack.h"

void greater_than(size_t *index) {
    if (*index >= BF_SIZE - 1) {
        fprintf(stderr, "\nError: Range error.\n");
        exit(EXIT_FAILURE);
    }

    (*index)++;
}

void less_than(size_t *index) {
    if (*index == 0) {
        fprintf(stderr, "\nError: Range error.\n");
        exit(EXIT_FAILURE);
    }

    (*index)--;
}

void plus(unsigned char *bf, size_t index) {
    bf[index]++;
}

void minus(unsigned char *bf, size_t index) {
    bf[index]--;
}

void dot(unsigned char *bf, size_t index) {
    printf("%c", bf[index]);
}

void comma(unsigned char *bf, size_t index, char *comma_inputs, size_t *comma_index) {
    bf[index] = comma_inputs[(*comma_index)++];
}

void open_bracket(size_t current_pos) {
    push(current_pos);
}

void close_bracket(unsigned char *bf, size_t index, size_t *i) {
    if (bf[index] == 0) {
        pop();
    } else {
        *i = peek();
    }
}

void execute_command(char c, size_t *i, char *comma_inputs) {
    static unsigned char bf[BF_SIZE] = {0};
    static size_t index = 0;
    static size_t comma_index = 0;

    switch (c) {
        case '>':
            greater_than(&index);
            break;
        case '<':
            less_than(&index);
            break;
        case '+':
            plus(bf, index);
            break;
        case '-':
            minus(bf, index);
            break;
        case '.':
            dot(bf, index);
            break;
        case ',':
            comma(bf, index, comma_inputs, &comma_index);
            break;
        case '[':
            open_bracket(*i);
            break;
        case ']':
            close_bracket(bf, index, i);
            break;
    }
}
