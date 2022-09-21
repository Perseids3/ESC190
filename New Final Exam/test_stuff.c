#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
    struct node *next;
    int value;
};

int count_links(struct node *node){
    int cur_max = -1;
    struct node* cur_node = node;
    while (cur_node != NULL){
        if (cur_node->value > cur_max){
            cur_max = cur_node->value;
        }
        cur_node = cur_node->next;
    }   // This takes N times

    int table[10000] = {0}; // Supposed to be cur_max, but     error: variable-sized object may not be initialized
    cur_node = node;
    while (cur_node->next != NULL){
        table[cur_node->value] += 1;
        cur_node = cur_node->next;
    }   // This takes N times as well
    int i;
    int check = 0;
    for (i = 0; i < cur_max+1; i++){
        if (table[i] != i){
            
            check = 0;

            break;
        } 
        else{
            check = 1;
        }
    } // M times. So in total O(2N + M) = O(N + M)
    return check;   
}

int main(void)
{
    struct node *n1 = (struct node *)malloc(sizeof(struct node));
    struct node *n2 = (struct node *)malloc(sizeof(struct node));
    struct node *n3 = (struct node *)malloc(sizeof(struct node));
    struct node *n4 = (struct node *)malloc(sizeof(struct node));

    n1->value = 1;
    n1->next = n2;
    n2->value = 2;
    n2->next = n3;
    n3->value = 2;
    n3->next = n4;
    n4->value = 3;
    n4->next = NULL;

    printf("%d\n", count_links(n1)); // 0

}