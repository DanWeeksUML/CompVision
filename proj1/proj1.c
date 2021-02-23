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
    int childArray[100];
    pid_t parent, pid, child;
    int end, i, forkNum, random;
    int childNum = 0;
    char testCommand[7];
    testCommand[0] = '.';
    testCommand[1] = '/';
    testCommand[2] = 't';
    testCommand[3] = 'e';
    testCommand[4] = 's';
    testCommand[5] = 't';
    testCommand[6] = 5 + '0';

    
    parent = getpid();
    printf("Parent pid is %d\n", parent);

    for (int i = 1; i <= atoi(argv[1]); i++) {
        forkNum = fork();
        if (forkNum == 0) {
            pid = getpid();
            printf("Statred child %d with pid %d\n", i, pid);
            srand(i);
            random = rand() % 5 + 1;
            testCommand[6] = random + '0';
            execlp(testCommand, "test", NULL);
            printf("TESTNAME: %s\n", testCommand);
            return 0;
        }
        else {
            childArray[i] = forkNum;
        }
    }
    i = 0;
    while (i < atoi(argv[1])) {
        child = wait(&end);
        for (int i = 1; i <= atoi(argv[1]); i++) {
            if (child == childArray[i]) {
                childNum = i;
                break;
            }
        }
        printf("Child %d (PID %d) is finished\n", childNum, child);
        i++;
    }

    printf("Parent (PID %d) is finished\n", parent);
    return 0;
}