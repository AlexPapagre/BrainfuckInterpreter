#include <stdio.h>
#include <stdlib.h>
#include "args.h"
#include "comma_input.h"
#include "input.h"
#include "bf.h"

int main(int argc, char *argv[]) {
    check_args(argc, argv[0]);

    int comma_counter = 0;
    char *code = read_bf_code(argc, argv[1], &comma_counter);

    printf("Clean input (commands only):\n");
    printf("%s\n\n", code);

    get_comma_inputs(comma_counter);

    run_bf_code(code);

    free_comma_inputs(comma_counter);
    free(code);

    return 0;
}
