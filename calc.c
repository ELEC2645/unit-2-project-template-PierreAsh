#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "calc.h"
#include "menu.h"
#include "utils.h"

void addition(void) {
    long x, y;

    if (validate_int(&x, "\nEnter the first number to add:\n") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    if (validate_int(&y, "Enter the second number to add:\n") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    printf("\n%ld + %ld = %ld\n", x, y, x + y);
    go_back_to_main();
}


void subtraction(void) {
    long x, y;

    if (validate_int(&x, "\nEnter the number to subtract FROM:\n") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    if (validate_int(&y, "Enter the number to subtract:\n") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    printf("\n%ld - %ld = %ld\n", x, y, x - y);
    go_back_to_main();
}

void multiplication(void) {
    long x, y;

    if (validate_int(&x, "\nEnter the first number to multiply:\n") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    if (validate_int(&y, "Enter the second number to multiply:\n") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    printf("\n%ld * %ld = %ld\n", x, y, x * y);

    go_back_to_main();
}

void division(void) {
    long temp_x, temp_y;

    if (validate_int(&temp_x, "\nEnter the numerator (the number to be divided):\n") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    if (validate_int(&temp_y, "Enter the denominator (the number you're dividing by):\n") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    if (temp_y == 0) {
        printf("\nCannot divide by zero.\n");
        go_back_to_main();
        return;
    }

    float result = (float)temp_x / (float)temp_y;

    printf("\n%ld / %ld = %.2f\n", temp_x, temp_y, result);

    go_back_to_main();
}

void power(void) {
    long base, exp;

    if (validate_int(&base, "\nEnter the base number:\n") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    if (validate_int(&exp, "Enter the exponent (between -10 and 20):\n") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    if (exp > 20 || exp < -10) {
        printf("Exponent too large in magnitude. Try something between -10 and 20.\n");
        go_back_to_main();
        return;
    }

    if (base == 0 && exp < 0) {
        printf("0 raised to a negative exponent is undefined.\n");
        go_back_to_main();
        return;
    }

    if (exp == 0) {
        printf("\n%ld^0 = 1\n", base);
        go_back_to_main();
        return;
    }

    if (exp > 0) {
        long result = 1;
        for (long i = 0; i < exp; i++) {
            if (base != 0 && (result > LONG_MAX / base || result < LONG_MIN / base)) {
                printf("Overflow: result too large for long.\n");
                go_back_to_main();
                return;
            }
            result *= base;
        }

        printf("\n%ld^%ld = %ld\n", base, exp, result);
        go_back_to_main();
        return;
    }

    if (exp < 0){
        long pos_exp = -exp;
        long power_val = 1;

        for (long i = 0; i < pos_exp; i++) {
            if (base != 0 && (power_val > LONG_MAX / base || power_val < LONG_MIN / base)) {
                printf("Overflow result too large for long.\n");
                go_back_to_main();
                return;
            }
            power_val *= base;
        }

        float result = 1.0f / (float)power_val;
        printf("\n%ld^%ld = %.4f\n", base, exp, result);
        go_back_to_main();
        return;
    }
}

void square_root(void) {
    long x;

    if (validate_int(&x, "\nEnter a non-negative number to take the square root of:\n") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    if (x < 0) {
        printf("Cannot take the square root of a negative number.\n");
        go_back_to_main();
        return;
    }

    float result = sqrtf((float)x);

    printf("\nsqrt(%ld) = %.2f\n", x, result);

    go_back_to_main();
}

void modulo(void) {
    long x, y;

    if (validate_int(&x, "\nEnter the dividend (the number to be divided):\n") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    if (validate_int(&y, "Enter the divisor (the number you're dividing by):\n") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    if (y == 0) {
        printf("Cannot perform modulo by zero.\n");
        go_back_to_main();
        return;
    }

    long result = x % y;

    printf("\n%ld %% %ld = %ld\n", x, y, result);

    go_back_to_main();
}

void factorial(void) {
    long n;

    if (validate_int(&n, "\nEnter a non-negative number to compute its factorial:\n") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    if (n < 0) {
        printf("Factorial of a negative number is not defined.\n");
        go_back_to_main();
        return;
    }
    if (n > 20) {
        printf("Number too large. Maximum allowed is 20.\n");
        go_back_to_main();
        return;
    }

    unsigned long long result = 1;

    for (long i = 1; i <= n; i++) {
        result *= i;
    }

    printf("\n%ld! = %llu\n", n, result);

    go_back_to_main();
}

void logarithm(void) {
    long x;

    if (validate_int(&x, "\nEnter a positive number to take log10 of:\n") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    if (x <= 0) {
        printf("Logarithm is only defined for positive numbers.\n");
        go_back_to_main();
        return;
    }

    float result = log10f((float)x);

    printf("\nlog10(%ld) = %.6f\n", x, result);

    go_back_to_main();
}

void percentage(void) {
    long value, percent;

    // Get the base value
    if (validate_int(&value, "\nEnter the base number (the value you want a percentage of): ") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    if (llabs(value) > 1000000000000L) {
        printf("Number too large for percentage calculation.\n");
        go_back_to_main();
        return;
    }

    if (validate_int(&percent, "Enter the percentage (e.g., 15 for 15%): ") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    if (llabs(percent) > 1000000000000L) {
        printf("Percentage too large for calculation.\n");
        go_back_to_main();
        return;
    }

    double result = (double)value * (double)percent / 100.0;

    printf("\n%ld%% of %ld = %.2f\n", percent, value, result);

    go_back_to_main();
}

void sine(void) {
    long angle_deg;

    if (validate_int(&angle_deg, "\nEnter an angle in degrees: ") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    float radians = (float)angle_deg * (M_PI / 180.0f);
    float result = sinf(radians);

    printf("\nsin(%ld°) = %.6f\n", angle_deg, result);

    go_back_to_main();
}

void cosine(void)
{
    long degrees;

    if (validate_int(&degrees, "\nEnter an angle in degrees for cosine: ") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }
    double radians = (double)degrees * (M_PI / 180.0);
    double result = cos(radians);

    printf("\ncos(%ld°) = %.6f\n", degrees, result);

    go_back_to_main();
}

void tangent(void)
{
    long degrees;

    if (validate_int(&degrees, "\nEnter an angle in degrees for tangent: ") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }
    double radians = (double)degrees * (M_PI / 180.0);

    // Check if tangent is undefined (cos ≈ 0)
    double cos_val = cos(radians);

    if (fabs(cos_val) < 1e-12) { 
        printf("\nTangent is undefined at %ld°.\n", degrees);
        go_back_to_main();
        return;
    }
    double result = tan(radians);

    printf("\ntan(%ld°) = %.6f\n", degrees, result);

    go_back_to_main();
}

void inverse_sine(void)
{
    double x;

    if (validate_double(&x, "\nEnter a value between -1 and 1 for arcsin: ") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    if (x < -1.0 || x > 1.0) {
        printf("arcsin is only defined for values between -1 and 1.\n");
        go_back_to_main();
        return;
    }

    double radians = asin(x);
    double degrees = radians * (180.0 / M_PI);

    printf("\narcsin(%g) = %.2f radians = %.2f°\n", x, radians, degrees);

    go_back_to_main();
}

void inverse_cosine(void)
{
    double x;

    if (validate_double(&x, "\nEnter a value between -1 and 1 for arccos: ") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    // Domain check
    if (x < -1.0 || x > 1.0) {
        printf("arccos is only defined for values between -1 and 1.\n");
        go_back_to_main();
        return;
    }

    double radians = acos(x);
    double degrees = radians * (180.0 / M_PI);

    printf("\narccos(%g) = %.2f radians = %.2f°\n", x, radians, degrees);

    go_back_to_main();
}

void inverse_tangent(void)
{
    double x;

    if (validate_double(&x, "\nEnter a number for arctan: ") != 0) {
        printf("Input error.\n");
        go_back_to_main();
        return;
    }

    double radians = atan(x);
    double degrees = radians * (180.0 / M_PI);

    printf("\narctan(%g) = %.2f radians = %.2f°\n", x, radians, degrees);

    go_back_to_main();
}