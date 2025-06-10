#include <stdio.h>
#include <stdlib.h>
#include "bracket_stack.h"

size_t brackets[MAX];
int top = -1;

void push(size_t i) {
    if (!isFull()) {
        brackets[++top] = i;
    } else {
        fprintf(stderr, "Bracket stack overflow.\n");
        exit(EXIT_FAILURE);
    }
}

size_t pop() {
    if (!isEmpty()) {
        return brackets[top--];
    } else {
        fprintf(stderr, "UNBALANCED BRACKETS\n");
        exit(EXIT_FAILURE);
    }
}

size_t peek() {
    if (!isEmpty()) {
        return brackets[top];
    } else {
        fprintf(stderr, "UNBALANCED BRACKETS\n");
        exit(EXIT_FAILURE);
    }
}

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

int size() {
    return top + 1;
}
