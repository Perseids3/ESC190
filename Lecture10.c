#include <stdlib.h>
#include <stdio.h>

struct stack{
    int *data;
    int size; // the size of the data block data
    int n;    // current number of elements on the stack
};

void create_stack(struct stack *stack){
    stack->size = 1;
    stack->data = (int *)malloc(stack->size * sizeof(int));
    stack->n = 0;
}


void push(struct stack *stack, int elem){
    if (stack->size == stack->n){
        stack->data = realloc(stack->data, stack->size * 2 * sizeof(int));
        stack->size *= 2;
    }
    stack->data[stack->n] = elem;
    stack->n++;
    // same as
    // stack->data[stack->n++] = elem;
}

int pop(struct stack *stack){
    return stack->data[--stack->n];
    // stack->n = stack->n - 1
    // return stack->data[stack->n];
    
}

int main(void)
{
    struct stack s1;
    create_stack(&s1);
    push(&s1, 5);
    push(&s1, 6);
    push(&s1, 8);
    printf("%d %d %d\n", s1.data[0], s1.data[1], s1.data[2]);
    printf("%d\n", pop(&s1));
    printf("%d\n", s1.n);
    printf("%d\n", s1.size);
}

// Reminder:
// a++ has the value (a+1) and the effect of incrementing a by 1
// ++a has the value a and the effect of incrementing a by 1

//int *a'
//*(a+i) is the same as a[i]