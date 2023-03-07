#include <stdio.h>

void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz){
    for (int i = 0; i < arr1_sz; i++){
        for (int j = 0; j < arr2_sz; j++){
            if (*(arr1+i) == *(arr2+j)){
                *(arr1+i) = 0;
            }
        }
    }
}

int main(){
    int a[] = {5, 6, 7, 8, 6, 7};
    int b[] = {6, 7};
    seq_replace(a, 6, b, 2);
    for(int i = 0; i < 6; i++){
        printf("%d\n", a[i]);
    }
}

// O(n^2)
// O(n*m), n is len(a), m is len(b)
// int *a = {5, 6, 7, 8, 6, 7};
	// this is very unvalid??? causes program to fail
// int *a = a_1
