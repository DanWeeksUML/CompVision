//================= p r o j 1 . c =========================
// Daniel Weeks
// EECE.5811 Operating Systems
// Due 2/24/2021

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int children[100] = { 0 };

void store(pid_t pid, int num) {
    children[num] = pid;
}

//int access(pid_t pid) {
//    for (int i = 1; i < 100; i++) {
//        if (children[i] == pid)
//            return i;
//    }
//    return 0;
//}

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
    int childNum = 0;
    parent = getpid();
    printf("Parent pid is %d\n", parent);
    if (fork() == 0) {
        pid = getpid();
        store(pid, 1);
        printf("Child pid is %d\n", pid);
        return 1;
    }
    else {
        pid = getpid();
        child = wait(&end);
        for (int i = 1; i < 100; i++) {
            if (children[i] == pid)
                childNum = i;
        }
        printf("Child %d (PID %d) is finished\n", childNum, child);
    }

    return 0;
}