#include <stdio.h>

int main() {
    int x = 5;
    int *ptr = &x;
    int **doublePtr = &ptr;

    printf("Using pointer: %d\n", *ptr);
    printf("Using double pointer: %d\n", **doublePtr);

    return 0;
}
