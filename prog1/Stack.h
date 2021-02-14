#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

struct stkNode {
    struct stkNode* prev;
    int value;
};

struct stack {
    struct stkNode* top;
};

struct stack* stackCreate(void);

void push(struct stack* stk, int value);

int stackEmpty(const struct stack* stk);

int pop(struct stack* stk);


void stackDestroy(struct stack* stk);


#endif