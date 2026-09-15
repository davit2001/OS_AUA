#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{   
    int status1, status2;
    pid_t child1, child2;
    child1 = fork();

    if (child1 < 0) {
        perror("fork failed");
        return 1;
    }

    if (child1 == 0) {
        printf("Child PID: %d\n", getpid());
        return 0;
    }

    child2 = fork();

    if (child2 < 0) {
        perror("fork failed");
        return 1;
    }

    if (child2 == 0) {
        printf("Child 2 PID: %d\n", getpid());
        return 2;
    }

    
    waitpid(child2, &status2, 0);

    if (WIFEXITED(status2)) {
        printf("Child 2 exit status: %d\n", WEXITSTATUS(status2));
    }

     wait(&status1);

    if (WIFEXITED(status1)) {
        printf("Child 1 exit status: %d\n", WEXITSTATUS(status1));
    }

    return 0;
}
