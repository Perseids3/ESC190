#include <stdio.h>
#include <stdlib.h>

void remove_str(char *s1, char *s2){
    int b = 0;
    int i = 0;
    while(s2[i]!= '\0'){
        i++;
    }
    int k = 0;
    while(s1[k]!= '\0'){
        k++;
    }
    int m = 0;
    for (m = 0; m < k - i; m++){
        if(s1[m] == s2[0]){
            int n = 0;
            int check = 0;
            for (n = 0; n<i; n++){
                if(s1[m+n] == s2[n]){
                    check = 1;
                }
                else{
                    check = 0;
                    break;
                }
            }
            if (check == 1){
                int a;
                b ++;
                
                for (a = 0; a < k-m-i; a++){

                    s1[m+a] = s1[m+i+a]; 
                }
                s1[k-b*i] = '\0';
            }
        }
    }  
}