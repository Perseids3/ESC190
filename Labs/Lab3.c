#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// P1
char *my_strcat(char *dest, char *src){
    while (*dest != '\0'){
        dest ++;
    }
    while (*src != '\0'){
        *dest++ = *src++;
    }
    return dest;
}

// P2
int my_strcmp_rec(char *str1, char *str2){
    if (*str1 == *str2){
        str1++;
        str2++;
    }
    if (*str1 != *str2){
        return (int)(*str1) - (int)(*str2);
    }
    if (*str1 == NULL && *str2 == NULL){
        return 0;
    }
    
    return my_strcmp_rec(str1, str2);
    
}


// P3
int my_atoi(char *str){
    int value = 0;
    int len = strlen(str);
    int i = 0;
    while(i < len){
        int to_add = str[i] -'0';
        to_add *= pow(10, len-1-i);
        value += to_add;
        //printf("%d\n", p);
        i++;
        }
        printf("converted to integer: %d\n", value);
    return value;
}


// P4
struct node{
    int data;
    struct node* next;
};


int cycle(struct node *head){
    if (head->next->next == NULL){
        return 0;
    }
    struct node* slower = head;
    struct node* faster = head;
    while ((faster->next != '\0')&&(slower->next != '\0')){
        faster = faster->next->next;
        slower = slower->next;
        if (faster == slower){
            return 1;
        }
    }return 0;
}


int main(){
// Part 1
    char str1[100] = "I hate ";
    char str2[] = "Praxis :< \n";
    strcat(str1, str2);
    printf("%s",str1);

// Part 2
    my_strcmp_rec(str1, str2);
    int a;
    a = strcmp(str1, str2);
    a = my_strcmp_rec(str1, str2);
    printf("str1[i]-str2[i] is %d\n", a);
    if(a < 0) {
        printf("str1 is less than str2\n");
    } else if(a > 0) {
        printf("str2 is less than str1\n");
    } else {
        printf("str1 is equal to str2\n");
    }
// Part 3
    char str3[10] = "13825";
    my_atoi(str3);

// Part 4
    
    struct node* node0 = (struct node*)malloc(sizeof(struct node));
    struct node* node1 = (struct node*)malloc(sizeof(struct node));
    // struct node* node2 = (struct node*)malloc(sizeof(struct node));
    // struct node* node3 = (struct node*)malloc(sizeof(struct node));
    // struct node* node4 = (struct node*)malloc(sizeof(struct node));
    node0 -> data = 0;
    node1 -> data = 1;
    // node2 -> data = 2;
    // node3 -> data = 3;
    // node4 -> data = 4;
    node0->next = node1;
    node1->next = NULL;
    // node2->next = node3;
    // node3->next = node4;
    // node4->next = node1;
    // node4->next = NULL;            //circle

    int c = cycle(node0);
    if(c==1) printf("Circle found");
    else printf("No circle");
    return 0;
}


   


// 2. Write a recursive version of strcmp. The signature must be
//    int my_strcmp_rec(char *str1, char *str2).
//    The function should return 0 if the contents of str1 and str2
//    are the same.

//    If the contents of str1 and str2 are not the same, and the first
//    character that doesn't match is at location i, the function
//    should return str1[i]-str2[i].

//    Each character corresponds to an integer value. For example,
//    'A' corresponds to 65, 'B' corresponds to 66, ..., 'Z' 
//    corresponds to 90, 'a' corresponds to 97, 'b' corresponds to
//    98, ... 

//    https://simple.wikipedia.org/wiki/ASCII#/media/File:ASCII-Table-wide.svg

//    Returning the difference between the first pair of unmatched characters
//    makes it so that strcmp returns a negative value if str1 comes before
//    str2 in a lexicographic order.


