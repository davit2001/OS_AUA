#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t child1, child2;
    int status1, status2;

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
        printf("Second child process\n");
        exit(5);
    }

    waitpid(child2, &status2, 0);

    if (WIFEXITED(status2)) {
        printf("Second child exit status: %d\n", WEXITSTATUS(status2));
    }

    wait(&status1);

    if (WIFEXITED(status1)) {
        printf("First child exit status: %d\n", WEXITSTATUS(status1));
    }

    printf("Parent process done\n");

    return 0;
}
