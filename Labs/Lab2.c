#include <stdio.h>
#include <stdlib.h>

struct node{
    int data; 
    struct node *next; 
};
// Problem 1
void print_all(struct node*head){
    struct node *cur = head;
    while (cur->next != NULL){
        printf("%d\n",cur->data);
        cur = cur->next;
    }
    printf("%d\n", cur->data);
}
// Problem 2
void print_all_rec(struct node*head){
    struct node * cur = head;
    if(cur->next == NULL){
        printf("%d\n",cur->data);
    
    } 
    printf("%d\n",cur->data);
    print_all_rec(cur->next);
}


// Problem 3
struct node1{
    void *p_data; //a pointer to data (allocated with malloc)
    int type; // 0 if int, 1 if float, 2 if double
    struct node1 *next;
};

void append_int(struct node1*head, int value){
    struct node1 *cur = head;
    while (cur->next != NULL){
        cur = cur->next;
    }
    struct node1 * to_add = (struct node1*)malloc(sizeof(struct node1));
    int *a = (int*)malloc(sizeof(int));  
    *a = value;
    cur->next = to_add;
    to_add->type = 0;
    to_add->p_data = (void *)a;
    to_add->next = NULL;
}
void append_float(struct node1*head, float value){
    struct node1 *cur = head;
    while (cur->next != NULL){
        cur = cur->next;
    }
    struct node1 * to_add = (struct node1*)malloc(sizeof(struct node1));
    float *a = (float*)malloc(sizeof(float));  
    *a = value;
    cur->next = to_add;
    to_add->type = 1;
    to_add->p_data = (void *)a;
    to_add->next = NULL;

}

void append_double(struct node1*head, double value){
    struct node1 *cur = head;
    while (cur->next != NULL){
        cur = cur->next;
    }
    struct node1 * to_add = (struct node1*)malloc(sizeof(struct node1));
    double *a = (double*)malloc(sizeof(double));  
    *a = value;
    cur->next = to_add;
    to_add->type = 2;
    to_add->p_data = (void *)a;
    to_add->next = NULL;
}
void print(struct node1 *cur){
    if(cur->next == NULL){
        if(cur->type == 0){
            printf("%d\n", *(int *)cur->p_data);
        }else if(cur->type == 1){
            printf("%f\n", *(float *)cur->p_data);
        }else{
            printf("%f\n", *(double *)cur->p_data);
        }
        return;
    }
    if(cur->type == 0){
        printf("%d\n", *(int *)cur->p_data);
    }else if(cur->type == 1){
        printf("%f\n", *(float *)cur->p_data);
    }else{
        printf("%f\n", *(double *)cur->p_data);
    }
    print(cur->next);
}

int main(){
    // Part 1 & 2:
    struct node *node0 = (struct node*)malloc(sizeof(struct node));
    node0->data = 3;

    struct node *node1 = (struct node*)malloc(sizeof(struct node));
    node0->next = node1;
    node1->data = 5;

    struct node *node2 = (struct node*)malloc(sizeof(struct node));
    node1->next = node2;
    node2->data = 8;
    node2->next = NULL;

    print_all(node0);
    print_all_rec(node0);

    // Part3 
    // struct node1 *node0 = (struct node1*)malloc(sizeof(struct node1));
    // int k = 3;
    // node0->p_data =  &k;
    // append_int(node0, 5);
    // append_double(node0, 2.3333);
    // append_float(node0, 3.1779879879);
    // print(node0);
    return 0;
}
