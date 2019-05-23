#include "apue.h"
#include "getPhyAddr.c"

int globvar = 6;

int main(void) {
    int var;
    pid_t pid;
    unsigned long phy;
    phy = mem_addr_vir2phy((unsigned long)&var);
    printf("real phy arrd of var in parten: 0x%lx\n",phy);

    var = 88;
    printf("before vfork\n");
    if ((pid = vfork()) < 0) {
        err_sys("vfork error");
    } else if(pid == 0) {
        globvar++;
        var++;
        exit(0);
    }

    phy = mem_addr_vir2phy((unsigned long)&var);
    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
    printf("real phy addr of var in child: 0x%lx\n", phy);
    exit(0);
}
