#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

void push(size_t i);
size_t pop();
size_t peek();
bool is_empty();

#endif
