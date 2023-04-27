#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct term{
    char term[20]; // assume terms are not longer than 200
    double weight;
} term;

int compare_terms(const void *p_a, const void *p_b){
    term *p_a_s = (term *)p_a;
    term *p_b_s = (term *)p_b;
    return strcmp(p_a_s->term, p_b_s->term);
}

int compare_weights(const void *p_a, const void *p_b){
    term *p_a_s = (term *)p_a;
    term *p_b_s = (term *)p_b;
    return p_b_s->weight-p_a_s->weight;
}

void read_in_terms(term **terms, int *pnterms){
    int num_terms = 3;
    *pnterms = num_terms;
    *terms = (term *)malloc((*pnterms)*sizeof(term));

    (*terms)->weight = 52;
    strcpy((*terms)->term, "Toronto, Canada");
    (*terms+1)->weight = 199;
    strcpy((*terms+1)->term, "Torino, Italy");
    (*terms+2)->weight = 199;
    strcpy((*terms+2)->term, "Shanghai, China");
    qsort(*terms, *pnterms, sizeof(term), compare_terms);
}

int lowest_match(term *terms, int nterms, char *substr){
    int left = 0;
    int right = nterms - 1;
    int length = 0;
    while (*(substr+length) != '\0'){
        length++;
    }
    while (left<=right){
        int mid = (left + right)/2;
        char res[length+1];
        strncpy(res, ((terms+mid)->term), sizeof(res)-1);
        res[length] = '\0';
        if (strcmp(res, substr) < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    printf("%d\n", left);
    return left;
}

int highest_match(struct term *terms, int nterms, char *substr){
    int left = 0;
    int right = nterms - 1;
    int length = 0;
    while (*(substr+length) != '\0'){
        length++;
    }
    int i = 0;
    while (left<=right){
        int mid = (left + right)/2;
        char res[length+1];
        strncpy(res, ((terms+mid)->term), sizeof(res)-1);
        res[length] = '\0';
        if (strcmp(res, substr) <= 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    printf("%d\n", right);
    return right;
}

void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr){
    int low = lowest_match(terms, nterms, substr);
    int high = highest_match(terms, nterms, substr);
    *n_answer = high-low+1;
    *answer = (term *)malloc((*n_answer)*sizeof(term));
    for (int j = 0; j<*n_answer; j++){
        (*answer+j)->weight = (terms+j+low)->weight;
        strcpy((*answer+j)->term, (terms+j+low)->term);
    }
    qsort(*answer, *n_answer, sizeof(term), compare_weights);
    return;
}

int main() {
    struct term *terms;
    int nterms;
    read_in_terms(&terms, &nterms);
    struct term *answer;
    int n_answer;
    autocomplete(&answer, &n_answer, terms, nterms, "Tor");
}