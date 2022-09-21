// 2. (15 pts)
//    Write a recursive version of the function strncmp. A description of strncmp 
//    is below:
//    Compares up to num characters of the C string str1 to those of the C string str2.
//    This function starts comparing the first character of each string. If they are
//    equal to each other, it continues with the following pairs until the characters
//    differ, until a terminating null-character is reached, or until num characters 
//    match in both strings, whichever happens first.

//    Return values:
//    <0	the first character that does not match has a lower value in str1 than in str2
//     0 	the contents of both strings are equal
//    >0	the first character that does not match has a greater value in str1 than in str2

//    "<0" means any negative number and ">0" means any positive number -- which numbers
//    exactly you return is up to you.

//    You may *not* use any C library functions. You may not use helper functions.

//    Signature:
//    int my_strncmp (char *str1, char *str2, int num );

//    Sample call:
//    my_strncmp("ESC180", "ESC190", 3); # returns 0
//    my_strncmp("ESC180", "ESC190", 5); # returns a negative number


//    Submit the file Q2.c that contains the implementation of my_strncmp, and 
//    *DOES NOT CONTAIN A MAIN FUNCTION*.
#include <stdio.h>
#include <stdlib.h>
int my_strncmp (char *str1, char *str2, int num ){
    if (num == 0){
        return 0;
    }
    else if ((str1)[num-1] != (str2)[num-1]){
        return (int)(*(str1+num-1)) - (int)(*(str2+num-1));
    }
    else{
        num--;
        return my_strncmp(str1, str2,num);   
    }
}



