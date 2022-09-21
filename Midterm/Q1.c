// 1. (15 pts)
//    Note that the number 523.12 can be written as
//    5x100^2 + 2x10^1 + 3x10^0 + 1x10^-1 + 2x10^-2

//    Write the function double my_atof(char *str) which takes in a string 
//    that contains a number in decimal notation str, and returns its value as a
//    double.
//    You can assume that the input is valid. You can assume there will be digits both
//    before and after the decimal point.

//    You may *not* use any C library functions. You may write your own helper functions.

//    Signature:
//    double my_atof(char *str);
   
//    Sample call:
//    my_atof("523.12") # returns the double 523.12

//    Double may not always be able to store the exact number. When testing, we will accept 
//    answers that are accurate to within 0.0001. You do not need to worry about overflow.

//    Submit the file Q1.c that contains the implementation of my_atof, and 
//    *DOES NOT CONTAIN A MAIN FUNCTION*.
#include <stdio.h>
#include <stdlib.h>

double my_atof(char *str){
    double value = 0;
    int len = strlen(str);
    int i = 0;
    int k = 0;
    int num_after_dec = 0;
    while(i < len){
        if (str[i] == '.'){
            num_after_dec = i;
            i++;
        }
        else{
            int to_add = str[i] -'0';
            to_add *= pow(10, len-2-k);
            value += to_add;

            i++;
            k++;
        }   
    }
    num_after_dec = i - num_after_dec-1;
    value *= pow(10,(-1 *num_after_dec));
    return value;
}

