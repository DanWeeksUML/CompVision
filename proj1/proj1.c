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
    if (argc < 2) {
        printf("PLEASE PASS NUMBER OF CHILDREN THROUGH COMMAND LINE\n");
        return 0;
    }
    int children[100];
    pid_t parent, pid, child;
    int end, i, forkNum;
    int childNum = 0;
    parent = getpid();
    printf("Parent pid is %d\n", parent);

    for (int i = 1; i <= atoi(argv[1]); i++) {
        forkNum = fork();
        printf("%d\n", forkNum);
        if (forkNum == 0) {
            pid = getpid();
            printf("Child pid is %d\n", pid);
            return 0;
        }
        else {
            children[i] = forkNum;
            printf("DEMON:%d\n", children[i]);
        }
    }
    i = 0;
    while (i < atoi(argv[1])) {
        child = wait(&end);
        printf("Child X (PID %d) is finished\n", child);
        i++;
    }

    printf("Parent (PID %d) is finished\n", parent);
    return 0;
}