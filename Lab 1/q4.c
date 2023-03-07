#include <stdio.h>

void sort_func(int arr[], int length){
    for (int i = 0; i < length-1; i++){
        int j = i;
        while (j >= 0 && arr[j+1] < arr[j]){
            int temp = *(arr+j);
            *(arr+j) = *(arr+j+1);
            *(arr+j+1) = temp;
            j = j - 1;
        }
    }
}

int main(){
    int arr1[] = {1, 2, 5, 3, 8, 10, 9};
    int length = sizeof(arr1) / sizeof(arr1[0]);
    sort_func(arr1, length);
    for(int i = 0; i < length; i++){
        printf("%d\n", arr1[i]);
    }
}