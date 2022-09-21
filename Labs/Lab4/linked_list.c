#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
void print_linked_list(struct node *head)
{
    while(head){ // while(head != NULL) ? 
        printf("%d\n", head->data);
        head = head->next;
    }
}
void insert(struct node *head, int value){
    struct node * new = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new;
    new->data = value; // Assume just append the element at the end?
}

void delete_node(struct node *head, int target){
    struct node* previous;
    struct node* temp = head;
    while (temp->next != NULL){
        if (temp->data == target){
            previous->next = temp->next;
            free(temp);
            break;
        }
        previous = temp;
        temp = temp->next;
    }
    if(temp->next == NULL){
        printf("%d is not found in the list.\n",target);
    }  
}

void free_them_all(struct node*head){
    struct node* next_one;
    struct node* temp;
    next_one = head->next;
    while (next_one->next != NULL){
        temp = next_one->next;
        free(next_one);
        next_one = temp;
    }
    free(next_one);
}