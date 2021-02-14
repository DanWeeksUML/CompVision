//================= L i n k e d L i s t . h =========================
// Daniel Weeks
// EECE.5811 Operating Systems
// Due 2/12/2021

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

//--------------- D A T A   S T R U C T U R E S -------------------

struct listNode {
    struct listNode* next;
    int value;
};

struct linkedList {
    struct listNode* head;
    struct listNode* current;
};

//--------------- F U N C T I O N S -------------------

struct linkedList* listCreate(void);

void insert(struct linkedList* list, int value);

int listEmpty(const struct linkedList* list);

int popList(struct linkedList* list);


void listDestroy(struct linkedList* list);

#endif