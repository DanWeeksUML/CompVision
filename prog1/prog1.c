//================= p r o g 1 . c =========================
// Daniel Weeks
// EECE.5811 Operating Systems
// Due 2/12/2021

#include <stdio.h>
#include "Queue.h"
#include "Stack.h"
#include "LinkedList.h"

int main(int argc, char** argv)
{
    //Check for the minumum number of command line arguments
    if (argc < 2) {
        printf("PLEASE ADD TEXT FILE NAME\n");
        return 0;
    }
    else
        printf("TEXT FILE SELECTED: %s\n", argv[1]);

    int i = 0;

    //Initialize queue, stack, and linked list data structures
    struct queue* q;
    struct stack* stk;
    struct linkedList* list;
    q = queueCreate();
    stk = stackCreate();
    list = listCreate();


    int c;
    FILE* file;
    file = fopen(argv[1], "r"); //open text file
    while (!feof(file))
    {
        fscanf(file, "%d", &c); //scan text file for integers

        //add each integer to all three data structures
        enq(q, c); //queue
        push(stk, c);  //stack
        insert(list, c);  //linked list
        
    }
    fclose(file);

    //Print all queue elements and free memory
    printf("QUEUE CONTENTS:\n");
    while (!queueEmpty(q)) {
        printf("%d ", deq(q));
    }

    //Print all stack elements and free memory
    printf("\nSTACK CONTENTS:\n");
    while (!stackEmpty(stk)) {
        printf("%d ", pop(stk));
    }

    //Print all linked list elements and free memory
    printf("\nLIST CONTENTS:\n");
    while (!listEmpty(list)) {
        printf("%d ", popList(list));
    }
    printf("\n");

    //Free memory of remaining data structures and their elements
    queueDestroy(q);
    stackDestroy(stk);
    listDestroy(list);

    return 0;
}