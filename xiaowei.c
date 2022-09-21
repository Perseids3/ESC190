#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Parameter is c is passed by value
// Meaning if you change the value of parameter in the function
// If will not affect the value of a in the main function
void change_a_to_4(int i){
    i = 4;
    return;
}

void change_value_of_ptr(int* i){
    // Let's malloc a new memory space and put the address in i;
    i = (int *)malloc(sizeof(int));
    printf("i's value (a memory address): %p\n",i);
    return;
}

void change_value_of_a_use_double_ptr(int **i){
    printf("i's value (memory address of answer): %p\n",i);
    printf("If we dereference i, we get value of i, which is memory address of a: %p\n",*i);
    printf("If we dereference i ,then dereference it again, we get value of a: %d\n",**i);
    // Since we have memory address of a, change the value of a is easy
    *(*i) = 4; // (*i) gives us address of a, use * again to change value of a
    printf("If we dereference i ,then dereference it again, we get value of a, now a is: %d\n",**i);
    // Let's go back and check the value of a in our main program
    return;
}

int main(){
    int a = 3;

    // Parameter is c is passed by value
    // Meaning if you change the value of parameter in the function
    // If will not affect the value of a in the main function
    printf("--------------------Part 1---------------\n");
    change_a_to_4(a);
    printf("%d\n",a);

    // Same applies to pointer
    printf("--------------------Part 2---------------\n");
    int *ptr = &a;
    printf("ptr's value (a memory address): %p\n",ptr);
    change_value_of_ptr(ptr);
    printf("However ptr's value will not change, after change_value_of_ptr function, ptr's value is : %p\n",ptr);

    // Same concept applies to double ptr as well
    printf("--------------------Part 3---------------\n");
    int *answer = &a;
    // answer's value is a memory address (int a's memory address)
    printf("answer's value (a memory address of int a): %p\n",ptr);
    // But where is the pointer answer located in the memory? Use &(dereference operator) will tell use about dat
    printf("answer's memory address (a memory address of int pointer (answer )): %p\n",&answer);
    // So the correct way to change the value of int a in a function will be:
    // Pass the address of answer (&answer) into a function, let's call it i 
    // type of i will be int**, because &a gives us answer, &answer gives us i, so i is int**
    // In the function, if we need to change the value of a, we can try to get memory address of a, and use that to change the value on that part of memory
    change_value_of_a_use_double_ptr(&answer);
    printf("Checking value of a in main program %d\n",a);
}