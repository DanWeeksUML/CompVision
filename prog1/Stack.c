//================= S t a c k . c =========================
// Daniel Weeks
// EECE.5811 Operating Systems
// Due 2/12/2021

#include "Stack.h"

//--------------- s t a c k C r e a t e ( ) -------------------
// Purpose: This function initializes a stack data structure

struct stack* stackCreate(void) {
    struct stack* stk;
    stk = malloc(sizeof(struct stack));
    stk->top = 0;
    return stk;
}

//--------------- p u s h ( ) -------------------
//Purpose: This function stores a value in a node that is
//placed at the top of the stack

void push(struct stack* stk, int value) {
    struct stkNode* e;
    e = malloc(sizeof(struct stkNode));
    e->value = value;
    e->prev = stk->top;
    stk->top = e;
}

//--------------- s t a c k E m p t y ( ) -------------------
//Purpose: This function determines if a atack is empty

int stackEmpty(const struct stack* stk) {
    return (stk->top == 0);
}

//--------------- p o p ( ) -------------------
//Purose: This function removes the top stack element, frees it from memory,
// and returns the value stored in that element.

int pop(struct stack* stk) {
    int temp;
    struct stkNode* e;
    temp = stk->top->value;
    e = stk->top;
    stk->top = e->prev;
    free(e);
    return temp;
}

//--------------- s t a c k D e s t r o y ( ) -------------------
//Purpose: This function empties all stack elements and frees thier memory

void stackDestroy(struct stack* stk) {
    while (!stackEmpty(stk)) {
        pop(stk);
    }

    free(stk);
}


