#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

static size_t stack[MAX];
static int top = -1;

bool is_empty() {
    return top == -1;
}

bool is_full() {
    return top == MAX - 1;
}

void push(size_t i) {
    if (!is_full()) {
        stack[++top] = i;
    } else {
        fprintf(stderr, "\nError: Bracket stack overflow.\n");
        exit(EXIT_FAILURE);
    }
}

size_t pop() {
    if (!is_empty()) {
        return stack[top--];
    } else {
        fprintf(stderr, "\nError: Unbalanced brackets.\n");
        exit(EXIT_FAILURE);
    }
}

size_t peek() {
    if (!is_empty()) {
        return stack[top];
    } else {
        fprintf(stderr, "\nError: Unbalanced brackets.\n");
        exit(EXIT_FAILURE);
    }
}

int size() {
    return top + 1;
}
