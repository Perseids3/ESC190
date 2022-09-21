#include <stdio.h>
#include <stdlib.h>

struct student_record{
    int esc180;
    int phy180;
}; // Need to have ; at the end of structs


// This method will not change the value of the input struct type variable
void no_effect(struct student_record s){
    s.esc180 = 233;
    
}

// Change the value of the address will do 
void have_effect(int *add){
    * add = 345;
}

void also_have_effect(struct student_record *ps){
    (*ps).esc180 = 97; 
    ps->esc180 = 199;
    // This is going to work because it takes in the pointer of a struct type value
    // Same as int *a
    // (*ps).esc180 = 97 is saying that: the content at the address (struct), then use .esc180 = 97

    /* An alternative notation for (*a).b is a->b  */
}

int *make_array(int size_arr){
    return (int *)malloc(size_arr * sizeof(int));
}

// A wrong example of making an array.
// int *make_arr_wrong(){
//     int a[10];
//     return a;
    // First, not allowed to say a[size]
    // Second, this will be a local thing, cannot be used.
// }

int main()
{
    // the address of the struct type and the elemengts stored:
    // the struct type variable will have the same address as the 
    // first element, similar to array
    struct student_record student;
    student.esc180 = 100;
    student.phy180 = 100;

    /* Casting:
    change type
    int a = 111;
    (float)a  will make it a float, an example is shown below
    */
    printf("%ld, %ld, %ld", (long int)&student, (long int)&student.esc180, (long int)&student.phy180);
    /* malloc */
    int *a = (int *)malloc(10 * sizeof(int));
    printf("\n%d\n",(int)sizeof(a));
    // malloc(a number) = give me (a number) of bytes in the memory model
    // malloc itself is a void pointer
    // do casting to this, in the example, that will be the type of the fourty bytes 
    // should be int pointer. Then, a will be a pointer that have 10 blocks in the md. 
    // Then we can do a[1], a[2] = 2; ...
    // This is useful when we do not know the size of the array, but we want to use this


    // To free memory, just use free()
    free(a); 
    // 
    return 0;
}