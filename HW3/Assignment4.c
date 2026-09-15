#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


int main()
{
   int stat1, stat2;
   pid_t child1, child2;

   child1 = fork();

   if (child1 < 0) {
    perror("fork of child1 failed");
    return 1;
   }

   if (child1 == 0) {
    printf("Child 1 id: %d\n", getpid());
    exit(0);
   }

   child2 = fork();

   if (child2 < 0) {
    perror("fork of child2 failed");
    exit(3);
   }

   if (child2 == 0) {
    printf("Child 2 id: %d\n", getpid());
    exit(3);
   }

   waitpid(child1, &stat1, 0);
   waitpid(child2, &stat2, 0);
   
   if (WIFEXITED(stat1)) {
        int code = WEXITSTATUS(stat1);

        printf("Child 1 exit status: %d\n", code);

        if (code == 0)
            printf("Child 1 exited normally\n");
        else
            printf("Child 1 exited with an error\n");
    }

    if (WIFEXITED(stat2)) {
        int code = WEXITSTATUS(stat2);

        printf("Child 2 exit status: %d\n", code);

        if (code == 0)
            printf("Child 2 exited normally\n");
        else
            printf("Child 2 exited with an error\n");
    }

    return 0;
}
