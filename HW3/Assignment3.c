#include <stdio.h>
#include <stdlib.h>

void func1(void) {
    printf("atexit() func1!\n");
}

void func2(void) {
    printf("atexit() func2!\n");
}

int main()
{
    atexit(func1);
    atexit(func2);

    printf("Main program\n");

    exit(0);

    printf("This will not run\n");

    return 0;
}
