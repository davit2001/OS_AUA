
#include <stdio.h>

struct Normal {
    char a;
    int b;
    double c;
};

#pragma pack(push, 1)
struct Packed1 {
    char a;
    int b;
    double c;
};
#pragma pack(pop)

#pragma pack(push, 2)
struct Packed2 {
    char a;
    int b;
    double c;
};
#pragma pack(pop)

#pragma pack(push, 4)
struct Packed4 {
    char a;
    int b;
    double c;
};
#pragma pack(pop)

int main() {
    struct Normal s1;
    struct Packed1 s2;
    struct Packed2 s3;
    struct Packed4 s4;

    printf("Normal Struct:\n");
    printf("Size = %zu bytes\n", sizeof(s1));
    printf("char a: %p\n", (void *)&s1.a);
    printf("int b: %p\n", (void *)&s1.b);
    printf("double c: %p\n", (void *)&s1.c);

    printf("\nPacked Struct (1):\n");
    printf("Size = %zu bytes\n", sizeof(s2));
    printf("char a: %p\n", (void *)&s2.a);
    printf("int b: %p\n", (void *)&s2.b);
    printf("double c: %p\n", (void *)&s2.c);

    printf("\nPacked Struct (2):\n");
    printf("Size = %zu bytes\n", sizeof(s3));
    printf("char a: %p\n", (void *)&s3.a);
    printf("int b: %p\n", (void *)&s3.b);
    printf("double c: %p\n", (void *)&s3.c);

    printf("\nPacked Struct (4):\n");
    printf("Size = %zu bytes\n", sizeof(s4));
    printf("char a: %p\n", (void *)&s4.a);
    printf("int b: %p\n", (void *)&s4.b);
    printf("double c: %p\n", (void *)&s4.c);

    return 0;
}
