#include "LinkedList.h"


struct linkedList* listCreate(void)
{
    struct linkedList* list;
    list = malloc(sizeof(struct linkedList));
    list->head = 0;
    list->current = list->head;
    return list;
}


void insert(struct linkedList* list, int value)
{
    struct listNode* e;
    e = malloc(sizeof(struct listNode));
    e->value = value;

    //If list is empty, create first node
    if (list->head == 0) {
        e->next = 0;
        list->head = e;
    }

    //If the new value is lower than the head's value, add node to front of list
    else if (list->head->value >= value){
        e->next = list->head;
        list->head = e;
        
    }
    else {

        //Scan the list for a value greater than the new one
        while (list->current->next != 0 && list->current->next->value < value) {
            list->current = list->current->next;
        }
        //If there is no greater value, add new node to back of the list
        if (list->current->next == 0) {
            e->next = 0;
            list->current->next = e;
        }
        //If greater value found, add new node before it
        else {
            e->next = list->current->next;
            list->current->next = e;
        }
    }
    list->current = list->head;
}


int listEmpty(const struct linkedList* list)
{
    return (list->head == 0);
}

int popList(struct linkedList* list)
{
    int temp;
    struct listNode* e;
    temp = list->head->value;
    e = list->head;
    list->head = list->head->next;
    free(e);
    return temp;
}


void listDestroy(struct linkedList* list)
{
    while (!listEmpty(list)) {
        popList(list);
    }

    free(list);
}