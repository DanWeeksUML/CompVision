//================= p r o j 1 . c =========================
// Daniel Weeks
// EECE.5811 Operating Systems
// Due 2/24/2021

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    //Check for the minumum number of command line arguments
    //if (argc < 2) {
    //    printf("PLEASE ADD TEXT FILE NAME\n");
    //    return 0;
    //}
    //else
    //    printf("TEXT FILE SELECTED: %s\n", argv[1]);
    pid_t parent, pid, child;
    int end;
    parent = getpid();
    printf("Parent pid is %d\n", parent);
    if (fork() == 0) {
        pid = getpid();
        printf("Child pid is %d\n", pid);
        return 1;
    }
    else {
        pid = getpid();
        printf("Parent pid is %d\n", pid);
        child = wait(&end);
        printf("Child %d (PID %d) is finished\n", end, child);
    }

    return 0;
}