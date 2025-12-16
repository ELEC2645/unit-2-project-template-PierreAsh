#include "utils.h"

void flush_input_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { /* discard */ }
}


int validate_int(long *out, const char *prompt) {
    char buf[1024];
    long value;
    int success;

    do {
        printf("%s", prompt);

        if (!fgets(buf, sizeof(buf), stdin)) {
            return 1;
        }

        char *endptr;
        errno = 0;
        value = strtol(buf, &endptr, 10);

        if (errno == ERANGE || endptr == buf || (*endptr && *endptr != '\n')) {
            printf("Invalid number\n");
            success = 0;
        } else {
            success = 1;
        }

    } while (!success);

    *out = value;
    return 0;
}

int validate_double(double *out, const char *prompt) {
    char buf[1024];
    double value;
    int success;

    do {
        printf("%s", prompt);

        if (!fgets(buf, sizeof(buf), stdin)) {
            return 1; 
        }

        char *endptr;
        errno = 0;
        value = strtod(buf, &endptr);

        if (errno == ERANGE || endptr == buf || (*endptr && *endptr != '\n')) {
            printf("Invalid number\n");
            success = 0;
        } else {
            success = 1;
        }

    } while (!success);

    *out = value;
    return 0;
}