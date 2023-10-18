#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */int main(void) {
    int len, len2;

    len = _printf("%S", "\\x0A");
    len2 = printf("\\x0A");
    fflush(stdout);
    if (len != len2) {
        printf("Lengths differ.\n");
        _printf("%s", "\\x0A");
      printf("\\x0A");
      printf("\n%d\n", len);
      printf("%d", len2);
        fflush(stdout);
        return 1;
    }
    return 0;
}
