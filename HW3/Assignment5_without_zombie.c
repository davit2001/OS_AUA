#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t child = fork();

    if (child < 0) {
        perror("fork failed");
        return 1;
    }

    if (child == 0) {
        printf("Child PID: %d\n", getpid());
        return 0;
    }

    printf("Parent PID: %d\n", getpid());

    wait(NULL);

    sleep(20);

    return 0;
}
