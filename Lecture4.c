#include <stdio.h>
#include <stdlib.h>

/*
Just remember one thing:
If a function takes in an array as the parameter:
IT IS A POINTER. NOT AN ARRAY.
IF YOU WANT IT TO BE AN ARRAY,
DO THE FOR LOOP
*/

/*
Binary System
1 Byte = 8 bits
*/

void print_arr(int *arr, int length)
{
    int i = 0;
    for(i = 0; i < length; i++)
    {
        printf("%d\n", arr[i]);
    }
}

/* 
Struct will give you a new type of variable
Kind of like dictionary
*/
struct student_record
{
    int Praxis_I_mark;
    int Praxis_II_mark;
    // So the size of it will be 8 bytes (2 * 4 bytes)
};
int main()
{
    int a[4] = {1,2,3,4};
    //print_arr(a, 4);

    struct student_record student1; 
    // You can initialize them by 
    // struct student_record student1 = {67, 75};
    student1.Praxis_I_mark = 67;
    student1.Praxis_II_mark = 75;
    struct student_record office[10];
    office[2].Praxis_I_mark = 10;
    office[3].Praxis_II_mark = 92;
    printf("%ld",office[3].Praxis_II_mark);
    // Similary to array, you cannot print the whole thing at once
    // You can do it separately 
    return 0;
}