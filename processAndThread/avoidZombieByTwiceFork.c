#include "apue.h"
#include <sys/wait.h>

int main() {
    pid_t pid;
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0) {
        if ((pid = fork()) < 0)
            err_sys("fork error");
        else if (pid > 0) {
            printf("\nsecond process pid = %ld\n", (long)getpid());
            exit(0);
        }
        sleep(2);
        printf("\nsecond child, pid = %ld, parent pid = %ld\n",(long)getpid(), (long)getppid());
        exit(0);
    } else {
        printf("\nfisrt process pid = %ld\n", (long)getpid());
    }

    if (waitpid(pid, NULL, 0) != pid) {  // wait for first child
        err_sys("waipid error\n");
    } else {
        printf("\n waitedFirstChild pid = %ld\n", (long)pid);
    }
    exit(0);
} 
