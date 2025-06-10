#ifndef BRACKET_STACK_H
#define BRACKET_STACK_H

#define MAX 1000

extern size_t brackets[MAX];
extern int top;

void push(size_t i);
size_t pop();
size_t peek();
int isFull();
int isEmpty();
int size();

#endif
