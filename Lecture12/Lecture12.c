#include <stdio.h>
#include <stdlib.h>
// typedef to rename types

typedef float my_float;

// size_t is defined in stdlib
// an integer that stores a size of a block of memory
/*
struct node{
    int data;
    struct node *next;
};
*/

typedef struct node{
    int data;
    struct node *next;
} node; // Consider this as one line.

int main(void)
{
    node n1;
    n1.data = 5;

    node *pn1 = (node *)malloc(sizeof(node));
    pn1->data; //(*pn1).data
    // my_float a = 3.14;
    const int a = 5; // a is of type const int
                     // integer that cannot be changed

    printf("%d\n", a);
    //a = a + 2;
    
    int *b = (int *)&a;
    *b = 4;
    printf("%d\n", a);
    
    //Or: //*(int *)(&a) = 3;
    
    int d = 5;
    const int *p_d = &d; // cannot change (the value) *p_d, silimar to const int a; but CAN change p_d
    int * const p_d1 = &d; // cannot change p_d1, CAN change *p_d1
                           // cannot say p_d1++, or p_d1 = &e
    const int * const p_d2; //cannot change both p_d2 and *p_d2

}