#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
struct term{
    char term[200]; // assume terms are not longer than 200
    double weight;
};

double my_atof(char *str){
    double value = 0;
    int len = strlen(str);
    int i = 0;
    int num_after_dec = 0;
    printf("%d",len);
    while(i < len){
        if (str[i] == '.'){
            continue;
            num_after_dec = i;
            i++;
            printf("Meet dec");
        }
        int to_add = str[i] -'0';
        to_add *= pow(10, len-2-i);
        value += to_add;
        //printf("%d\n", p);
        i++;
        printf("%d",i);
    }
    num_after_dec = i - num_after_dec;
    value *= pow(10,(-1 *num_after_dec));
    return value;
}
int my_strncmp (char *str1, char *str2, int num ){
    printf("%c",(*str1)[0]);
    printf("%c",(*str1)[1]);
    printf("%c",(*str1)[2]);
    // str1+=num;
    // str2+=num;
    // if (num == 0){
    //     return 0;
    // }
    // else if (*str1 != *str2){
    //     return (int)(*str1) - (int)(*str2);
    // }
    // else{
    //     num--;
    //     return my_strncmp(str1, str2,num);   
    // }


    // if (*str1 == '\0' | *str2 == '\0'){
    //     return 0;
    // }
    // if (*str1 != *str2){
    //     return (int)(*str1) - (int)(*str2);
    // }
    // return mystrncmp(str1[], str2,num-1);   
}


int main(){
    char * string1;
    string1[0] = '3';
    string1[1] = '2';
    string1[2] = '1';
    string1[3] = '.';
    string1[4] = '6';
    string1[5] = '6';
    char * string2;
    string2[0] = '3';
    string2[1] = '2';
    string2[2] = '1';
    string2[3] = '.';
    string2[4] = '6';
    string2[5] = '6';
    my_strncmp(string1,string2,3);
    
    // my_atof(string);
    // try(&string);
    // printf("%d",strcmp("Abc","Abb"))

    return 0;
}
