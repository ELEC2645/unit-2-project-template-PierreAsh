#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void flush_input_buffer(void);
int validate_int(long *out, const char *prompt);
int validate_double(double *out, const char *prompt);


#endif