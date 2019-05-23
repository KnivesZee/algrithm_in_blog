#include "apue.h"
#include "getPhyAddr.c"

int globvar = 6;
char buf[] = "a write to stdout\n";

int main(void) {
    int var;
    pid_t pid;
    unsigned long phy;

    var = 88;
    printf("before fork:\n"); // we don't flush stdout

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        globvar++;
        var++;
    } else {
        sleep(2);
    }

    phy = mem_addr_vir2phy((unsigned long)&var);
    printf("pid = %ld, glob = %d, var = %d \n", (long)getpid(), globvar, var);
    printf("addr of var : %p\n", &var);
    printf("real phy addr of var: 0x%lx\n", phy);
    exit(0);
}
