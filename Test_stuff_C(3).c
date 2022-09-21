#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
struct term{
    char term[200]; // assume terms are not longer than 200
    double weight;
};


// int my_strcmp_rec_edited(char *str1, char *str2){
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
        int identifier = strncmp(terms[mid].term, substr,strlen(substr));
        //printf("%d\n",identifier);
        if (identifier == 0){
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
        // printf("%f\n",(*answer)[i].weight);
        indicator++;
        i++;
    }
    //qsort(answer[0], *n_answer, sizeof(struct term), (*compar(const void *, const void*)) not sure how to use
    for(int k = 1; k < (highest - lowest +1); k++){
        int j = k - 1;
        while((j > -1) && ((*answer)[j].weight < (*answer)[j+1].weight)){
            double temp_weight = (*answer)[j].weight;
            char * temp_term = (char *)malloc(sizeof(char)*200);
            strcpy(temp_term, (*answer)[j].term); 
            (*answer)[i].weight =  (*answer)[j+1].weight;
            strcpy((*answer)[j].term, (*answer)[j+1].term);
            strcpy((*answer)[j+1].term,temp_term); 
            (*answer)[j+1].weight = temp_weight;
            j--;
            free(temp_term);
        }
    }
}

static int compare_(const struct term*a, const struct term*b) {
    return strcmp(a->term, b->term);
}
int compare_1 (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
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
        double weight = (double)(atoi(temp_weight));
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



void try(char ** string){
    *string = (char*)malloc(sizeof(char)*1000);
    (*string)[0] = 'c';
    (*string)[1] = 'c';
    (*string)[2] = 'c';
    (*string)[3] = 'c';
    (*string)[4] = 'c';
    (*string)[1012312] = 'c';
}




int main(){

    // char * string;
    // string[0] = 'c';
    // string[1] = 'c';
    // string[2] = 'c';
    // printf("%s",string);
    // try(&string);
    // printf("%d",strcmp("Abc","Abb"));



    // struct term * terms = (struct term*)malloc(5*sizeof(struct term));
    // terms[0].term[0] = 'A';
    // terms[0].term[1] = 'a';
    // terms[0].term[2] = 'a';
    // terms[0].term[3] = 'd';
    // terms[0].term[4] = 'd';
    // terms[0].weight = 2;


    // terms[1].term[0] = 'A';
    // terms[1].term[1] = 'a';
    // terms[1].term[2] = 'c';
    // terms[1].term[3] = 'b';
    // terms[1].term[4] = 'b';
    // terms[1].weight = 3;
    

    // terms[2].term[0] = 'A';
    // terms[2].term[1] = 'c';
    // terms[2].term[2] = 'c';
    // terms[2].term[3] = 'c';
    // terms[2].term[4] = 'c';
    // terms[2].weight = 4;


    // terms[3].term[0] = 'B';
    // terms[3].term[1] = 'a';
    // terms[3].term[2] = 'b';
    // terms[3].term[3] = 'c';
    // terms[3].term[4] = 'd';
    // terms[3].weight = 4.0;


    // terms[4].term[0] = 'B';
    // terms[4].term[1] = 'a';
    // terms[4].term[2] = 'b';
    // terms[4].term[3] = 's';
    // terms[4].term[4] = 'd';
    // terms[4].weight = 5.0;


    // terms[5].term[0] = 'B';
    // terms[5].term[1] = 'a';
    // terms[5].term[2] = 'b';
    // terms[5].term[3] = 'z';
    // terms[5].term[4] = 's';
    // terms[5].weight = 6.0;

  
    
    // char* str1 = (char*)malloc(10*sizeof(char));
    // char* str2 = (char*)malloc(3*sizeof(char));
    // str1[0] = 'B';
    // str1[1] = 'b';
    // str1[2] = 'd';
    // str1[3] = 'c';
    // str1[4] = 'm';

    // str2[0] = 'A';
    // str2[1] = 'A';
    // str2[2] = 'B';
    // str2[3] = 'c';
    struct term *terms;
    int nterms;
    struct term *answer;
    int n_answer;
    // printf("%d",isdigit('c'));
    // printf("%d\n",isdigit('1'));
    // printf("%d",isdigit('c'));
    // struct term * qsorttest = (struct term*)malloc(3*sizeof(struct term));
    // strcpy(qsorttest[0].term, "Farī");
    // strcpy(qsorttest[1].term, "Fari");
    // strcpy(qsorttest[2].term, "Farj");
    // qsort(qsorttest, 3, sizeof(struct term), compare_1);

    // printf("%s\n",qsorttest[0].term);
    // printf("%s\n",qsorttest[1].term);
    // printf("%s\n",qsorttest[2].term);


    read_in_terms(&terms, &nterms, "cities1.txt");
    autocomplete(&answer, &n_answer, terms, nterms, "S");
    printf("%s\n",(answer)[0].term);
    printf("%s\n",(answer)[1].term);
    printf("%s\n",(answer)[2].term);
    //printf("%s\n",(&answer)[2]->term);
   
    


    //read_in_terms(&terms, &nterms, "wiktionary.txt");
    // int m = 0;
    // for (m=0; m<nterms; m++){
    //     printf("%s\n",terms[m].term);
    // }


    // char * filename = "wiktionary.txt";
    // FILE *fp = fopen(filename, "r");
    // // for(int i = 0; i < N; i++){
    // //     fgets(line, sizeof(line), fp); 
    // char line[200];
    // fgets(line, sizeof(line), fp);
    // fgets(line, sizeof(line), fp);
    // char * temp_char = (char*)malloc(sizeof(char)*200);
    // char * temp_weight = (char *)malloc(200*sizeof(char));
    // int k =0;
    // int k_for_temp_char = 0;
    // int k_for_temp_weight = 0;
    // while (isdigit(line[k]) == 0){ // isdigit(' ')或者'\t'都是0
    //         k++;
    //     }
    // while (isdigit(line[k])!= 0){ // 取下数字
    //         temp_weight[k_for_temp_weight] = line[k];
    //         k_for_temp_weight++;
    //         k++;
    //     }

    // while ((int)line[k] <48){ // 不能isdigit，因为后面isdigit都是0，但是要取下tab（或者空格）  空格和tab 的ascii 码都比48要小
    //         k++;
    //     }
    // while (line[k]!= '\n'){  //结尾会是'\n'后面跟着一个'\0'，应该是这样
    //         temp_char[k_for_temp_char] = line[k];
    //         k_for_temp_char++;
    //         k++;
    //     }
    // printf("%s\n",temp_char);
    // printf("%s\n",temp_weight);

    // printf("%d",isdigit(' '));

    // printf("%d",(int)(' '));
    // if (line[1] == ' '){
    //     printf("%c",'a');
    // }
    

    return 0;
}
