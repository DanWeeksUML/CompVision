
#include "Queue.h"


struct queue* queueCreate(void)
{
    struct queue* q;
    q = malloc(sizeof(struct queue));
    q->head = q->tail = 0;
    return q;
}

void enq(struct queue* q, int value)
{
    struct node* e;
    e = malloc(sizeof(struct node));
    e->value = value;
    e->next = 0;
    if (q->head == 0) {
        q->head = e;
    }
    else {
        q->tail->next = e;
    }
    q->tail = e;
}

int queueEmpty(const struct queue* q)
{
    return (q->head == 0);
}

int deq(struct queue* q)
{
    int temp;
    struct node* e;
    temp = q->head->value;
    e = q->head;
    q->head = e->next;
    free(e);
    return temp;
}


void queueDestroy(struct queue* q)
{
    while (!queueEmpty(q)) {
        deq(q);
    }

    free(q);
}
