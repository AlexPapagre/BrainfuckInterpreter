#include "check.h"
#include <stdio.h>
#include <stdlib.h>

void usage_message(const char *bf) {
    fprintf(stderr, "Usage 1: %s\n", bf);
    fprintf(stderr, "Usage 2: %s <filename>\n", bf);
}

void check_args(int argc, const char *bf) {
    if (argc > 2) {
        usage_message(bf);
        exit(EXIT_FAILURE);
    }
}