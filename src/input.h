#ifndef INPUT_H
#define INPUT_H

void check_args(int argc, char *bf);
char *read_bf_code(int argc, char *filename, int *comma_counter);
char *get_comma_inputs(int comma_counter);

#endif
