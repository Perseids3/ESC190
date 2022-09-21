#include "intset.h"
// struct intset{
//     struct node *head;
// };

// struct node{
//     int data;
//     struct node *next;
// };

//Create an intset, and place a pointer to it in *s.
void intset_create(struct intset **s){
    *s = (struct intset*)malloc(sizeof(struct intset));
}

//Add the elements from array elems to intset s. There are
//num_elems elements in elems
void intset_add(struct intset *s, int *elems, int num_elems){
    int i = 0;
    s = (struct intset *)malloc(sizeof(struct intset));
    s->head = (struct node*)malloc(sizeof(struct node)*num_elems);
    struct node *cur = s->head;
    while (i < num_elems){
        cur->data = elems[i];
        cur = cur->next;
        i++;
    }
}

//Return 1 if element elem is in intset s. Otherwise return 0.
int intset_iselem(struct intset *s, int elem){
    struct node * cur = s->head;
    while(cur->data != elem){
        if (cur->next == NULL){
            return 0;
        }
        else{
            cur = cur->next;
        }  
    }
    return 1;
}


//Remove element elem from s, of eleme is in s. If the element 
//is not in s, do nothing.
//free memory that's not needed anymore
void intset_remove(struct intset *s, int elem){
    struct node * cur = s->head;
    while(cur->data != elem){
        if (cur->next == NULL){
            return;
        }
        else{
            cur = cur->next;
        }  
    }
    cur = cur->next;
}


//Compute the union of sets s1 and s2, and place the
//result in a new intset *s3.
void intset_union(struct intset *s1, struct intset *s2, struct intset **s3){
    *s3 = (struct intset *)malloc(sizeof(struct intset)*2);
    struct node * cur1 = s1->head;
    struct node * cur2 = s2->head;
    while (cur1->next != NULL){
        cur1= cur1->next;
    }
    cur1->next = cur2;
    (*s3)->head = cur1;
}