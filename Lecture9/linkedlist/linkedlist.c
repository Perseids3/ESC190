#include <stdio.h>
#include "linkedlist.h"
void printlinkedlist(struct node *head)
{
    while(head){ // head != NULL ?
        printf("%d\n", head->data);
        head = head->next;
    }
}