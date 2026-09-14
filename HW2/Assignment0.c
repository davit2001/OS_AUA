#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t ret;

    ret = fork();
    if (ret < 0) {
        perror("fork");
        exit(1);
    }

    ret = fork();
    if (ret < 0) {
        perror("fork");
        exit(1);
    }

    ret = fork();
    if (ret < 0) {
        perror("fork");
        exit(1);
    }

    printf("PID: %d, Parent PID: %d\n", getpid(), getppid());

    return 0;
}
