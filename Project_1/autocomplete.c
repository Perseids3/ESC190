#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "autocomplete.h"
#include <ctype.h>
// Part 1 ////////////////////////////////////////////
static int compare_(const struct term*a, const struct term*b) {
    return strcmp(a->term, b->term);
}
static int compare_w(const struct term*a, const struct term*b) {
    if((a->weight)==(b->weight)){
        return 0;
    }else if((a->weight)>(b->weight)){
        return -1;
    }else{
        return 1;
    }
}

void read_in_terms(struct term **terms, int *pnterms, char *filename){
    FILE *fp = fopen(filename, "r");
    char line[200];
    fgets(line, sizeof(line), fp);
    *pnterms = atoi(line);
    int N = *pnterms;
    *terms = (struct term *)malloc(sizeof(struct term)* N);
// 48 - 57 
    for(int i = 0; i < N; i++){
        fgets(line, sizeof(line), fp); 
        char * temp_char = (char *)malloc(200*sizeof(char));
        char * temp_weight = (char *)malloc(200*sizeof(char));
        int k = 0;
        int k_for_temp_char = 0;
        int k_for_temp_weight = 0;
        while (isdigit(line[k]) == 0){ // isdigit(' ')或者'\t'都是0
            k++;
        }
        while (isdigit(line[k])!= 0){ // 取下数字
            temp_weight[k_for_temp_weight] = line[k];
            k_for_temp_weight++;
            k++;
        }

        while (line[k] == '\t' | line[k] == ' '){   // 不能isdigit，因为后面isdigit都是0，但是要取下tab（或者空格）  
            k++;                                    // 这边还有更坑人的情况，也不能用 ascii码
        }
        while (line[k]!= '\n'){  //结尾会是'\n'后面跟着一个'\0'，应该是这样, isdigit不能使用
            temp_char[k_for_temp_char] = line[k];
            k_for_temp_char++;
            k++;
        }
        double weight = atof(temp_weight);
        strcpy((*terms)[i].term, temp_char);
        (*terms)[i].weight = weight;
        
        // free(temp_weight);
        // free(temp_char);
    }
    qsort(*terms, N, sizeof(struct term), compare_); // 应该可以
    // qsort(*terms, N, sizeof(struct term), compare_1); //不太行

// Manual: Change the order                             比上面那个略好
    // for(int m = 1; m < *pnterms; m++){
    //     int j = m - 1;
    //     //printf("J: %d\n",j);
    //     while((j > -1) && (strcmp((*terms)[j].term,(*terms)[j+1].term) == 1)){
    //         //printf("%d",strcmp((*terms)[j].term,(*terms)[j+1].term));
    //         float temp_weight = (*terms)[j].weight;
    //         char * temp_term = (char *)malloc(sizeof(char)*200);
    //         strcpy(temp_term, (*terms)[j].term); 
    //         (*terms)[j].weight =  (*terms)[j+1].weight;
    //         strcpy((*terms)[j].term, (*terms)[j+1].term);
    //         strcpy((*terms)[j+1].term,temp_term); 
    //         (*terms)[j+1].weight = temp_weight;
    //         j--;
    //         free(temp_term);
    //         }
    //     }
}  


// Part 2 ////////////////////////////////////////////

// int my_strcmp_rec_edited(char *str1, char *str2){                               // 这个有点像strncmp
//     if (*str1 == *str2){                                                         
//         str1++;                                                                  
//         str2++;
//     }
//     if (*str1 == '\0' | *str2 == '\0'){
//         return 0;
//     }
//     if (*str1 != *str2){
//         return (int)(*str1) - (int)(*str2);
//     }
//     return my_strcmp_rec_edited(str1, str2);   
// }

int lowest_match(struct term *terms, int nterms, char *substr){
    int first = 0;
    int last = nterms-1;
    int index = -1;
    while (first <= last && index == -1){
        int mid = (first+last)/2;
        int identifier = strncmp(terms[mid].term, substr,strlen(substr));          // strncmp的使用默认了substr的长度是小于词典里的词的
        // printf("%d\n",identifier);                                                  这应该是make sense 的, 如果可以extra func, strncmp 可以
        if (identifier == 0){                                                      // 改为 my_strcmp_rec_edited(terms[].term, substr)
            if (mid == 0){
                index = mid;
            }
            else if(strncmp(terms[mid-1].term, substr,strlen(substr)) != 0){
                index = mid;
            }
            else{
                last = mid;
            }
        }
        else if(identifier>0){
            last = mid;
        }
        else{
            first = mid;
        }
        // printf("%d",first);
        // printf("%d",last);
        if (first+1 == last){
            if(strncmp(terms[first].term, substr,strlen(substr)) == 0){
                index = first;
            }
            else if(strncmp(terms[last].term, substr,strlen(substr)) == 0){
                index = last;
            }
            else{
                break;
            }
        }
    }
    return index;
}

int highest_match(struct term *terms, int nterms, char *substr){
    int first = 0;
    int last = nterms-1;
    int index = -1;
    while (first <= last && index == -1){
        int mid = (first+last)/2;
        int identifier = strncmp(terms[mid].term, substr,strlen(substr));
        if (identifier == 0){
            if (mid == nterms-1){
                index = mid;
            }
            else if(strncmp(terms[mid+1].term, substr,strlen(substr)) != 0){
                index = mid;
            }
            else{
                first = mid;
            }
        }
        else if(identifier>0){
            last = mid;
        }
        else{
            first = mid;
        }
        if (first+1 == last){
            if(strncmp(terms[last].term, substr,strlen(substr)) == 0){
                index = last;
            }
            else if(strncmp(terms[first].term, substr,strlen(substr)) == 0){
                index = first;
            }
            else{
                break;
            }
        }
    }
    return index;
}

// Part 3 ////////////////////////////////////////////

void autocomplete(struct term **answer, int *n_answer, struct term *terms, int nterms, char *substr){
    // answer = (struct term**)malloc(sizeof(struct term*));
    // *answer = (struct term*)malloc(100 *sizeof(struct term));
    int lowest = lowest_match(terms, nterms, substr);
    int highest = highest_match(terms, nterms, substr);
    // n_answer = (int *)malloc(sizeof(int));
    *n_answer = highest - lowest +1;
    int indicator = lowest;
    int i = 0;
    *answer = (struct term*)malloc(sizeof(struct term)* (*n_answer));
    while(indicator <= highest && indicator != -1){
        strcpy((*answer)[i].term,terms[indicator].term);
        // printf("%s\n",(*answer)[i].term);
        (*answer)[i].weight = terms[indicator].weight;
        indicator++;
        i++;
    }
    qsort(*answer, *n_answer, sizeof(struct term), compare_w);
    // for(int k = 1; k < (highest - lowest +1); k++){
    //     int j = k - 1;
    //     while((j > -1) && ((*answer)[j].weight < (*answer)[j+1].weight)){
    //         double temp_weight = (*answer)[j].weight;
    //         printf("%f",temp_weight);
    //         char * temp_term = (char *)malloc(sizeof(char)*200);
    //         strcpy(temp_term, (*answer)[j].term); 
    //         (*answer)[i].weight =  (*answer)[j+1].weight;
    //         strcpy((*answer)[j].term, (*answer)[j+1].term);
    //         strcpy((*answer)[j+1].term,temp_term); 
    //         (*answer)[j+1].weight = temp_weight;
    //         j--;
    //         free(temp_term);
    //     }
    // }
}



