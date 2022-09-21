#include <stdio.h>
#include <stdlib.h>

// append
// length
// max
// rec_length
// rec_max
// free
// malloc error



struct node{
    int data; //in python: void *data, and also the data type
    struct node *next; //NULL if the current node is the last one
};

void append(struct node *head, int value){
    struct node *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct node *node = (struct node *)malloc(sizeof(struct node));
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
int max(int a, int b){
    if (a > b){
        return a;
    } else{
        return b;
    }
}
int max_list_rec(struct node *head){
    if(head->next == NULL){
        return head->data;
    }else{
        return max(head->data, max_list_rec(head->next));
    }
}



int list_len_rec(struct node *head){
    if(head == NULL){
        return 0;
    }else{
        return 1 + list_len_rec(head->next);
    }
}

void free_list(struct node *head){
    struct node *next = NULL;
    while(head != NULL){
        next = head->next;
        free(head);
        head = next;
    }
    //while(head != NULL){
    //    free(head);
    //    head = head->next;
    //}
}

void free_list_rec(struct node *head){
    if(head == NULL){
        return;
    }else{
        free_list_rec(head->next);
        free(head);
    }
}

/*
   Create a node in memory using malloc, with data value
   Return 0 on success, 1 on failure
*/
int make_node(struct node **pnode, int value)
{
    *pnode = (struct node*)malloc(sizeof(struct node));
    if(*pnode == NULL){
        return 1;
    }else{
        (*pnode)->data = value;
        (*pnode)->next = NULL;
        return 0;
    }
}

int main(void)
{
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    
    node0->data = 3;
    node0->next = NULL;
    append(node0, 5);
    append(node0, 15);
    append(node0, 12);
    printf("%d\n", max_list_rec(node0));

    struct node *node1 = NULL;
    if(make_node(&node1, 5) == 1){
        printf("Error making node");
        return 1;
    }

    //struct node *node1 = (struct node *)malloc(sizeof(struct node));
    //node0->next = node1;
    //node1->data = 5;
    //node1->next = NULL;

    max_list_rec(node0);
    //max_list_rec(node1);

    //printf("hi\n");
    return 0;
}