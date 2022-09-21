#include <stdio.h>
#include <stdlib.h>
// Part I:
void turn_into_0(int *a)
{
    *a = 10;
}

// Part II:
void insertion_sort(int *array, int length){
    for(int i = 1; i < length; i++){
        int current = *(array + i);
        //printf("current is : %d\n", current);
        int j = i - 1;
        while((j > -1)&(*(array + j) > *(array + j+1))){
            int temp = *(array + j);
            *(array + j) = *(array + j+1);
            *(array + j+1) = temp;
            j--;
        }
    }
}

void print_array_helper(int *a, int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf(" %d",a[i]);
    } 
}

int main()
{
    // Part I
    int a = 5;
    int *p_a = &a;
    printf("The original value of a is: %d\n", a);
    turn_into_0(p_a); // Not sure whether better approach exists 
    printf("Now the value of a is: %d\n", a); 
    // Part II
    int array[7] = {7, -9, 21, 10, 7, -4, 3};
    int len = sizeof(array)/sizeof(array[0]);
    printf("Originally, the array will be like:\n");
    print_array_helper(array, len);
    insertion_sort(array,len);
    printf("\nNow, the array will be like:\n");
    print_array_helper(array, len);
    return 0; 
}

