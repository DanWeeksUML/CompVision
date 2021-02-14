//================= Q u e u e . h =========================
// Daniel Weeks
// EECE.5811 Operating Systems
// Due 2/12/2021

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

//--------------- D A T A   S T R U C T U R E S -------------------

struct node {
    struct node* next;
    int value;
};

struct queue {
    struct node* head;
    struct node* tail;
};

//--------------- F U N C T I O N S -------------------

struct queue* queueCreate(void);

void enq(struct queue* q, int value);

int queueEmpty(const struct queue* q);

int deq(struct queue* q);

void queueDestroy(struct queue* q);

#endif
