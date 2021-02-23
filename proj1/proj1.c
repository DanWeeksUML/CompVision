//================= p r o j 1 . c =========================
// Daniel Weeks
// EECE.5811 Operating Systems
// Due 2/24/2021

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

pid_t children[100];

//void store(pid_t pid, int num) {
//    children[num] = pid;
//}

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
    if (argc < 2) {
        printf("PLEASE PASS NUMBER OF CHILDREN THROUGH COMMAND LINE\n");
        return 0;
    }
    
    pid_t parent, pid, child;
    int end, i;
    int childNum = 0;
    parent = getpid();
    printf("Parent pid is %d\n", parent);

    for (int i = 1; i <= atoi(argv[1]); i++) {
        if (fork() == 0) {
            pid = getpid();
            children[1] = pid;
            printf("Child pid is %d\n", pid);
            return 0;
        }
    }
    for (int i = 1; i <= atoi(argv[1]); i++) {
        pid = getpid();
        child = wait(&end);
        for (i = 1; i < 100; i++) {
            if (children[i] == child)
                childNum = i;
        }
        printf("Child %d (PID %d) is finished\n");
    }

    printf("Parent is finished\n", childNum, child);
    return 0;
}