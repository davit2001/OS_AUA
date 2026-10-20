#include <stdio.h>

int main() {
    int i = 0;
    char ch = 0;
    double d = 0;
    short s = 0;

    printf("int: size = %zu, address = %p\n", sizeof(i), (void *)&i);
    printf("char: size = %zu, address = %p\n", sizeof(ch), (void *)&ch);
    printf("double: size = %zu, address = %p\n", sizeof(d), (void *)&d);
    printf("short: size = %zu, address = %p\n", sizeof(s), (void *)&s);

    return 0;
}
