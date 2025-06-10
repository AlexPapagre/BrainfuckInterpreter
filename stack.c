#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

size_t stack[MAX];
int top = -1;

void push(size_t i) {
    if (!is_full()) {
        stack[++top] = i;
    } else {
        fprintf(stderr, "Bracket stack overflow.\n");
        exit(EXIT_FAILURE);
    }
}

size_t pop() {
    if (!is_empty()) {
        return stack[top--];
    } else {
        fprintf(stderr, "UNBALANCED BRACKETS\n");
        exit(EXIT_FAILURE);
    }
}

size_t peek() {
    if (!is_empty()) {
        return stack[top];
    } else {
        fprintf(stderr, "UNBALANCED BRACKETS\n");
        exit(EXIT_FAILURE);
    }
}

bool is_empty() {
    return top == -1;
}

bool is_full() {
    return top == MAX - 1;
}

int size() {
    return top + 1;
}
