#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int hash(char * str){
    int res = 0;
    int i = 0;
    while(str[i]!='\0'){
        res += (int)(str[i]);
        i++;
    }
    return res;
}


int repeats(char **strs, int strs_sz){
    int res;
    int i;
    char* table[10000] = {};
    for(i = 0; i < strs_sz; i++){
        table[hash(strs[i])]++;
        if (table[hash(strs[i])]>1){
            res = 1;
            return res;
        }
    }
    res = 0;
    return res;
}

// Since the for loop in the repeats() will be O(n) and the rest
// of the function will cost constant time.
// The overall complexity will be O(n)