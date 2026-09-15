#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t child1;

    child1 = fork();

    if (child1 < 0) {
        perror("fork failed");
        return 1;
    }

    if (child1 == 0) {
        execl("/bin/echo", "echo", "Hello from the child process", NULL);
        perror("execl failed");
        return 1;
    }

    waitpid(child1, NULL, 0);

    printf("Parent process done\n");

    return 0;
}
