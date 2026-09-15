#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t child1, child2;

    child1 = fork();

    if (child1 < 0) {
        perror("fork failed");
        return 1;
    }

    if (child1 == 0) {
        execl("/bin/ls", "ls", NULL);
        perror("execl failed");
        exit(1);
    }

    child2 = fork();

    if (child2 < 0) {
        perror("fork failed");
        return 1;
    }

    if (child2 == 0) {
        execl("/bin/date", "date", NULL);
        perror("execl failed");
        exit(1);
    }

    waitpid(child1, NULL, 0);
    waitpid(child2, NULL, 0);

    printf("Parent process done\n");

    return 0;
}
