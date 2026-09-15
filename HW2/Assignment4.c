#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t child;

    child = fork();

    if (child < 0) {
        perror("fork failed");
        return 1;
    }

    if (child == 0) {
        execl("/usr/bin/grep", "grep", "main", "test.txt", NULL);
        perror("execl failed");
        return 1;
    }

    waitpid(child, NULL, 0);

    printf("Parent process done\n");

    return 0;
}
