#ifndef BRACKET_STACK_H
#define BRACKET_STACK_H

#include <stddef.h>
#include <stdbool.h>

#define MAX 1000

extern size_t brackets[MAX];
extern int top;

void push(size_t i);
size_t pop();
size_t peek();
bool isEmpty();
bool isFull();
int size();

#endif
