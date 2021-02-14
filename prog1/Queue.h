#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* next;
    int value;
};

struct queue {
    struct node* head;
    struct node* tail;
};

struct queue* queueCreate(void);

void enq(struct queue* q, int value);

int queueEmpty(const struct queue* q);

int deq(struct queue* q);

void queueDestroy(struct queue* q);

#endif
