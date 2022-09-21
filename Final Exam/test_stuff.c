#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
///////////////////////
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





int main(){

    ////// Q1

    // char *strs[] = {"ESC", "MAT", "MSE", "CIV"};
    // char *all = concat_all(strs, 4); 
    // printf("%s\n", all); //ESCMATMSECIV
    // free(all);

    ////// Q2
 

    char *strs[] = {"ESC", "MAT", "MSE", "CIV"};
    printf("%d",repeats(strs, 4)); // 0

//   char *strs[] = {"ESC", "MAT", "MSE", "CIV", "ESC"};
//   repeats(strs, 5) // 1

    return 0;

}