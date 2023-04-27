#include "autocomplete.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_terms(const void *p_a, const void *p_b){
    term *p_a_s = (term *)p_a;
    term *p_b_s = (term *)p_b;
    return strcmp(p_a_s->term, p_b_s->term);
}

int compare_weights(const void *p_a, const void *p_b){
    term *p_a_s = (term *)p_a;
    term *p_b_s = (term *)p_b;
    if (p_b_s->weight-p_a_s->weight == 0)
        return strcmp(p_a_s->term, p_b_s->term);
    return p_b_s->weight-p_a_s->weight;
}

void read_in_terms(term **terms, int *pnterms, char *filename){
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error: cannot open file %s\n", filename);
        return;
    }
    char line[200];
    fgets(line, 200, fp);
    line[strlen(line)-1] = '\0';
    int num_terms = atoi(line);
    *pnterms = num_terms;
    *terms = (term *)malloc((*pnterms)*sizeof(term));

    int j=0;
    while(fgets(line, 200, fp) != NULL && j < *pnterms){
        int i = 0;
        while (!(line[i] >= '0' && line[i] <= '9') && line[i] != '\t')
            i++;
        char *double_str = &(*(line+i));
        if(*double_str != '\0')
            (*terms+j)->weight = atof(double_str);
        while ((line[i] >= '0' && line[i] <= '9') && line[i] != '\t')
            i++;
        i++;
        char *char_str = &(*(line+i));
        int k = 0;
        while (*(char_str+k) != '\n' && *(char_str+k) != '\0'){
            k++;
        }
        char res[k+1];
        strncpy(res, char_str, sizeof(res)-1);
        res[k] = '\0';
        strcpy((*terms+j)->term, res);
        j++;
    }
    qsort(*terms, *pnterms, sizeof(term), compare_terms);
    fclose(fp);
    return;
}

int lowest_match(term *terms, int nterms, char *substr){
    int left = 0;
    int right = nterms - 1;
    int length = 0;
    while (*(substr+length) != '\0')
        length++;
    while (left<=right){
        int mid = (left + right)/2;
        if (strncmp((terms+mid)->term, substr, length) < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int highest_match(struct term *terms, int nterms, char *substr){
    int left = 0;
    int right = nterms - 1;
    int length = 0;
    while (*(substr+length) != '\0')
        length++;
    while (left<=right){
        int mid = (left + right)/2;
        if (strncmp((terms+mid)->term, substr, length) <= 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
}

void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr){
    int low = lowest_match(terms, nterms, substr);
    int high = highest_match(terms, nterms, substr);
    if (low > high)
        *n_answer = 0;
    else
        *n_answer = high-low+1;
    *answer = (term *)malloc((*n_answer)*sizeof(term));
    for (int j = 0; j<*n_answer; j++){
        (*answer+j)->weight = (terms+j+low)->weight;
        strcpy((*answer+j)->term, (terms+j+low)->term);
    }
    qsort(*answer, *n_answer, sizeof(term), compare_weights);
    return;
}