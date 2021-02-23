//================= p r o j 1 . c =========================
// Daniel Weeks
// EECE.5811 Operating Systems
// Due 2/24/2021

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    //Check for the minumum number of command line arguments
    //if (argc < 2) {
    //    printf("PLEASE ADD TEXT FILE NAME\n");
    //    return 0;
    //}
    //else
    //    printf("TEXT FILE SELECTED: %s\n", argv[1]);
    //pid_t pid;
    fork();
    printf("Hello\n");

    return 0;
}