#include <stdio.h>
#include <stdlib.h>

/*
In Python, list can:
1. Store any type of data
2. Store the address of that data
3. No limitation on the length


*/

struct node{
    int data; //in python: void *data, and also the data type
    struct node *next; //NULL if the current node is the last one
};
/*
What is going on here:

*/

void append(struct node *head, int value){
    struct node *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct node *node = (struct node *)malloc(10*sizeof(struct node));
    node->data = value;
    node->next = NULL;
    cur->next = node;
}

int max_list(struct node *head){
    struct node *cur = head;
    int curmax = cur->data;
    while(cur != NULL){
        if(cur->data > curmax){
            curmax = cur->data;
        }
        cur = cur->next;
    }
    
    return curmax;

}

int main(void)
{
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    node0->data = 3;

    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node0->next = node1;
    node1->data = 5;
    node1->next = NULL;


    printf("hi\n");
    return 0;
}