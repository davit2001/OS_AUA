#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    printf("Original array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptr);
        ptr++;
    }

    printf("\n");

    ptr = arr;

    for (int i = 0; i < 5; i++) {
        *ptr = *ptr * 2;
        ptr++;
    }

    ptr = arr;

    printf("Using pointer: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptr);
        ptr++;
    }

    printf("\n");

    printf("Using array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
