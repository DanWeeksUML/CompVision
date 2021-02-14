//================= Q u e u e . c =========================
// Daniel Weeks
// EECE.5811 Operating Systems
// Due 2/12/2021

#include "Queue.h"

//THIS CODE IS MODIFIED FROM THE CODE FOUND AT:
//https://www.cs.yale.edu/homes/aspnes/classes/223/examples/linkedLists/queue.c

//--------------- q u e u e C r e a t e ( ) -------------------
// Purpose: This function initializes a queue data structure

struct queue* queueCreate(void) {
    struct queue* q;
    q = malloc(sizeof(struct queue));
    q->head = q->tail = 0;
    return q;
}

//--------------- e n q ( ) -------------------
//Purpose: This function stores a value in a node that is
//placed at the tail of the queue

void enq(struct queue* q, int value) {
    struct node* e;
    e = malloc(sizeof(struct node));
    e->value = value;
    e->next = 0;

    //if the queue is empty, the node is placed at the head
    if (q->head == 0) {
        q->head = e;
    }
    //if the queue is not empty, the node is placed at the tail
    else {
        q->tail->next = e;
    }
    q->tail = e;
}

//--------------- q u e u e E m p t y ( ) -------------------
//Purpose: This function determines if a queue is empty

int queueEmpty(const struct queue* q) {
    return (q->head == 0);
}

//--------------- p o p L i s t ( ) -------------------
//Purose: This function removes the head queue element, frees it from memory,
// and returns the value stored in that element.

int deq(struct queue* q) {
    int temp;
    struct node* e;
    temp = q->head->value;
    e = q->head;
    q->head = e->next;
    free(e);
    return temp;
}

//--------------- q u e u e D e s t r o y ( ) -------------------
//Purpose: This function empties all queue elements and frees thier memory

void queueDestroy(struct queue* q) {
    while (!queueEmpty(q)) {
        deq(q);
    }

    free(q);
}
