#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "bf.h"

int main(int argc, char *argv[]) {
    check_args(argc, argv[0]);

    int comma_counter = 0;
    char *code = read_bf_code(argc, argv[1], &comma_counter);

    printf("Clean input (commands only):\n");
    printf("%s\n\n", code);

    char *comma_inputs = get_comma_inputs(comma_counter);

    run_bf_code(code, comma_inputs);

    if (comma_counter > 0) {
        free(comma_inputs);
    }
    free(code);

    return 0;
}
