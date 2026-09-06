#include <stdio.h>

int main() {
    int x = 5;
    int *y = &x;

    printf("Address using x: %p\n", (void *)&x);
    printf("Address using y: %p\n", (void *)y);
    printf("Value: %d\n", *y);

    *y = 10;

    printf("New value: %d\n", x);

    return 0;
}
