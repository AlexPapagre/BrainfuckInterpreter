#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdbool.h>

#define MAX 1000

void push(size_t i);
size_t pop();
size_t peek();
bool is_empty();

#endif
