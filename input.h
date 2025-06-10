#ifndef INPUT_H
#define INPUT_H

#include <stddef.h>

char *user_input(size_t *size, size_t *capacity, char *buffer, int *comma_counter);
char *file_input(char *filename, size_t *size, size_t *capacity, char *buffer, int *comma_counter);
void add_null_terminator(size_t size, size_t capacity, char *buffer);
char *comma_input(int comma_counter);

#endif
