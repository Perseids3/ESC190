#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* concat_all(char **strs, int strs_sz){
    //concatenate all strs_sz strings in strs, and return the resultant string
    
    int i = 0;
    int num = 0;
    
    for (i=0; i<strs_sz; i++){
        int j = 0;
        while(strs[i][j]!='\0'){
            num++;
            j++;
        }
    }
    char * res = (char *)malloc(sizeof(char)*num);
    i = 0;
    int num2 = 0;
    for (i=0; i<strs_sz; i++){
        int k = 0;
        while(strs[i][k]!='\0'){
            res[num2] = strs[i][k];
            k++;
            num2++;
        }
        k = 0;
    }
    return res;
}