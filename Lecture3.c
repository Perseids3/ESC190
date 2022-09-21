#include <stdio.h>
void show_difference(int a[])
{
    printf("However, sizeof(a) in the function is: %ld\n", sizeof(a));    
}
int main(void)
{
    // Array in C:
    int a[3] = {2, 3, 4};
    // Array's name: a; Array's length: 3; This need to be defined first.
    // then the data in the array can be stored like this = {1, 2, 3}
    // By default, the elements in the array will all be zeroes if not initialized(like a[10] = {})
    // int a[] requires all the elements in a are integers

    // Memory model for Array:
    // the name of the array ----> some address
    // that address's content ----> the first element of the array
    // the rest of the element will consecutively take the addresses following up the first element

    // This result in that the array will behave almost like pointer
    // *a will give the first element of the array
    // *a will be equivalent to a[0]
    // When you pass the array into a function:
    // function(int a[]) will be the exact same as function(int *a)
    // In that function, that array will be just a pointer which takes up 8 bytes
    



    /*
    If we do:
    int *p_a = &a[0],
    C knows it is an address, therefore, if we do:
    p_a + 1, it will knows that it should be the next block of address
    p_a + 2 will be the next of p_a + 1
    Therefore, *(p_a + 1) = a[1]; *p_a = a[0]
    In fact, when C see things like p_a[1], it will convert it into *(p_a + 1);
    For a, when we do a[100], C will convert it into *(a+100);
    That is why we say array will behave almost like pointer! 
    */

    /* 
    But there is difference between pointer and array:
    int *p_a = a;
    a = a + 1; will give an error
    p_a = p_a + 1; //no problem, p_a referes to the second element of a
    */
   


    int an_int = 0;        // 4
    float a_float = 0;     // 4
    double a_double = 0;   // 8
    long int a_long  = 0;  // 8
    char a_char = 'a';     // 1 Damn, for single character, must be single quotation mark
    // How to understand the idea of bytes
    // One block, 4 bytes.
    // 1024, 1028, 1032, 1036
    // For an integer, one integer, one block.
    // For an double, one integer, double block.
    // For an char, four char, one block
    printf("An double takes up %ld bytes\n", sizeof(a_double));
    printf("An char takes up %ld bytes\n", sizeof(a_char));
    printf("An float takes up %ld bytes\n", sizeof(a_float));
    printf("An long int takes up %ld bytes\n", sizeof(a_long));

    printf("sizeof(a) %ld\n", sizeof(a));                           // To get the total size of the a
    show_difference(a); // This indicates that, when array is passed into a function, it is considered
                        // as an pointer
    printf("sizeof(a)/sizeof(a[0]) %ld\n", sizeof(a)/sizeof(a[0])); // To get the length of the array

    return 0;

}
// In summary, consider the value of a as the address of the first element of the array
// when it can be considered as a pointer. When facing cases like a = a + 1, that is not ok.
