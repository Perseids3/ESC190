#include <stdlib.h>
#include "linkedlist.h"
int main(void)
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 5;
    head->next = NULL;
    printlinkedlist(head);
}