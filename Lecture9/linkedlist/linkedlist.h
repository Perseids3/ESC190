#if !defined(LINKEDLIST_H)
#define LINKEDLIST_H
struct node{
    int data;
    struct node *next;
};

void printlinkedlist(struct node *head);

#endif