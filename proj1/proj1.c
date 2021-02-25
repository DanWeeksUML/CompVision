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

    //Variables declared
    int childArray[999];
    pid_t parent, pid, child;
    int end, i, forkNum, random;
    int childNum = 0;
    int numberOfChildren;
    numberOfChildren = atoi(argv[1]);

    //Test file path string started, missing test number
    char testCommand[7];
    testCommand[0] = '.';
    testCommand[1] = '/';
    testCommand[2] = 't';
    testCommand[3] = 'e';
    testCommand[4] = 's';
    testCommand[5] = 't';
    
    parent = getpid();
    printf("Parent pid is %d\n", parent);


    //Parent uses this loop to create child processes 
    for (int i = 1; i <= numberOfChildren); i++) {
        forkNum = fork();

        //Child 
        if (forkNum == 0) {

            //Child process obtains pid and declares that it has started
            pid = getpid();
            printf("Statred child %d with pid %d\n", i, pid);

            //random number between 1 and 5 is obtained
            srand(i);
            random = rand() % 5 + 1;

            //random number is added test file path string
            testCommand[6] = random + '0';

            //random test file is executed
            execlp(testCommand, "test", NULL);
            return 0;
        }

        //Parent thread stores child thread pid in an array after creation
        else {
            childArray[i] = forkNum;
        }
    }


    i = 0;

    //Parent uses this loop to wait for all child processes to end
    while (i < numberOfChildren) {

        //Parent waits for child to end, obtains ended child's pid
        child = wait(&end);

        //Parent searches array to determine child number based on pid
        for (int i = 1; i <= numberOfChildren; i++) {
            if (child == childArray[i]) {
                childNum = i;
                break;
            }
        }
        //Print statement that specific child has ended
        printf("Child %d (PID %d) is finished\n", childNum, child);
        i++;
    }

    //All child processes are ended, parent process ends
    printf("Parent (PID %d) is finished\n", parent);
    return 0;
}