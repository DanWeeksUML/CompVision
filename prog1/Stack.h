//================= S t a c k . h =========================
// Daniel Weeks
// EECE.5811 Operating Systems
// Due 2/12/2021

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

//--------------- D A T A   S T R U C T U R E S -------------------

struct stkNode {
    struct stkNode* prev;
    int value;
};

struct stack {
    struct stkNode* top;
};

//--------------- F U N C T I O N S -------------------

struct stack* stackCreate(void);

void push(struct stack* stk, int value);

int stackEmpty(const struct stack* stk);

int pop(struct stack* stk);

void stackDestroy(struct stack* stk);


#endif