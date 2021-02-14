#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct listNode {
    struct listNode* next;
    int value;
};

struct linkedList {
    struct listNode* head;
    struct listNode* current;
};

struct linkedList* listCreate(void);

void insert(struct linkedList* list, int value);

int listEmpty(const struct linkedList* list);

int popList(struct linkedList* list);


void listDestroy(struct linkedList* list);

#endif