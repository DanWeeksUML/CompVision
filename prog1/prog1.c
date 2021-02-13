#include <stdio.h>
#include "Queue.h"
#include "Stack.h"
#include "LinkedList.h"

int main(int argc, char** argv)
{
    if (argc < 2) {
        printf("PLEASE ADD TEXT FILE NAME");
        return 0;
    }
    else
        printf("TEXT FILE SELECTED: %s\n", argv[1]);

    int i = 0;
    struct queue* q;
    struct stack* stk;
    struct linkedList* list;
    q = queueCreate();
    stk = stackCreate();
    list = listCreate();

    int last = 0;
    int current;
    int c;
    FILE* file;
    file = fopen(argv[1], "r");
    while (!feof(file))
    {
        fscanf(file, "%d", &c);
        enq(q, c);
        push(stk, c);
        insert(list, c);
        
    }
    fclose(file);


    printf("QUEUE CONTENTS:\n");
    while (!queueEmpty(q)) {
        printf("%d ", deq(q));
    }


    printf("\nSTACK CONTENTS:\n");
    while (!stackEmpty(stk)) {
        printf("%d ", pop(stk));
    }


    printf("\nLIST CONTENTS:\n");
    while (!listEmpty(list)) {
        printf("%d ", popList(list));
    }
    printf("\n");

    queueDestroy(q);
    stackDestroy(stk);
    listDestroy(list);

    return 0;
}