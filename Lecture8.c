#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int* f(){
//     int a[3];
//     return a;
// }

int* f1(){
    int *a = (int *)malloc(sizeof(int));
    return a;
}

void g(){
//  int *a = f();
//  a[0];//error

    int *b = f1();
    // b[0]; //OK
}

int my_strlen(char *s1)
{
    int len = 0;
    while(*s1 != '\0'){
        len++;  //len = len + 1
        s1++;
    }
    return len;
}

void my_strcpy(char *dest, char *src)
{
    while(*src != '\0'){
        *dest = *src;
        src++;
        dest++;
    }
    *dest = *src;
}


void my_strcpy2(char *dest, char *src)
{
    while(*src != '\0')
        *dest++ = *src++; //equivalent to *dest = *src; dest++; src++;

    *dest = *src;      
    //*++dest = *++src; // equivalent to dest++; src++; *dest = *src; 
}


int main(void)
{
    
    char c1 = 'a';
    char c2 = 'A';
    char *s1 =  "asdfjasdfj";
    // This means s1 is the address of the 
    // first element of the string
    // You cannot do things like:
    // s1[2] = 'z';
    char *s2 = (char *)malloc(sizeof(char) * 20);
    s2[0] = 'A';
    char s3[20];
    // "abc" is a string, C stores: ['a', 'b', 'c', NULL]
    char s4[4] = "ab";
    printf("%s\n", s4);  // It is %s, so it konws it should print like s4[0] s4[1] s4[2] ,
    printf("%c\n", *s4); // Now it is %c, so it works like this
    printf("%s\n", s1);  // You can also print this, but this is immutable.


    // copy string
    char s5[20] = "abc";
    char s6[20];
    strcpy(s6, s5); //s6 is destination, s5 is source
    //s6 = s5 is an error
    strlen(s5); //the length of s5 (num of characters, not counting NULL)
    strcmp(s5, s6); // <0 s5 comes before s6 in lexigroaphic ordering
                    // 0 if s5 and a6 are the same
                    // >0 otherwise

    // s5 and s6 can (is) be char* type!!!
    // not the same as s5 == s6 (for pointers, checks whether s5 and s6 are aliases)

    char *a = (char *)malloc(sizeof(char)*50);
    strcpy(a, "abcdefg");
    char *b = a;
    //b[2] = 'z' => a[2] is also 'z'

    return 0;
}
