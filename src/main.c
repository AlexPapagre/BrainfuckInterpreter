#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "bf.h"

int main(int argc, char *argv[]) {
    if (argc > 2) {
        fprintf(stderr, "Usage 1: %s\n", argv[0]);
        fprintf(stderr, "Usage 2: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int comma_counter = 0;
    char *buffer = read_bf_code(argc, argv[1], &comma_counter);

    printf("Clean input (commands only):\n");
    printf("%s\n\n", buffer);

    char *comma_inputs = comma_input(comma_counter);

    run_bf_code(buffer, comma_inputs);

    if (comma_counter > 0) {
        free(comma_inputs);
    }
    free(buffer);

    return 0;
}
