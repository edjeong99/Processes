// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

//--> variants give options to users when using exec.
//--> for example, arguments can be passed as list or array

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
  int rc = fork();
  
    if (rc < 0) {    // fork failed; exit
   
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
         printf("Children\n");
         execlp("ls", "ls", NULL);
        perror("exec");
         exit(1);   
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("Parent\n");
       }
    return 0;
}
