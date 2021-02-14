#include "Stack.h"

struct stack*
    stackCreate(void)
{
    struct stack* stk;
    stk = malloc(sizeof(struct stack));
    stk->top = 0;
    return stk;
}

void push(struct stack* stk, int value)
{
    struct stkNode* e;
    e = malloc(sizeof(struct stkNode));
    e->value = value;
    e->prev = stk->top;
    stk->top = e;
}

int stackEmpty(const struct stack* stk)
{
    return (stk->top == 0);
}

int pop(struct stack* stk)
{
    int temp;
    struct stkNode* e;
    temp = stk->top->value;
    e = stk->top;
    stk->top = e->prev;
    free(e);
    return temp;
}


void stackDestroy(struct stack* stk)
{
    while (!stackEmpty(stk)) {
        pop(stk);
    }

    free(stk);
}


