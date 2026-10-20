
#include <stdio.h>

struct Original {
    char a;
    int b;
    double c;
};

struct Reordered {
    double c;
    int b;
    char a;
};

int main() {
    struct Original s1;
    struct Reordered s2;

    printf("Original Struct:\n");
    printf("Struct size = %zu bytes\n", sizeof(s1));
    printf("char a: address = %p\n", (void *)&s1.a);
    printf("int b: address = %p\n", (void *)&s1.b);
    printf("double c: address = %p\n", (void *)&s1.c);

    printf("\nReordered Struct:\n");
    printf("Struct size = %zu bytes\n", sizeof(s2));
    printf("double c: address = %p\n", (void *)&s2.c);
    printf("int b: address = %p\n", (void *)&s2.b);
    printf("char a: address = %p\n", (void *)&s2.a);

    return 0;
}
