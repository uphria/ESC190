#include <stdio.h>

void to_10(int *p_a){
    *p_a = 10;
}

void change_arr(char *p_a, int length){
    int i;
    *(p_a+1) = 'b';
}

void change_arr1(char *p_a){
    *(p_a+1) = 'b';
    p_a[2] = 'c';
}

char *change_arr_char(char *arr){
    arr = "Bye World!!";
    return arr;
}

int main(){
    int a = 5;
    to_10(&a);
    printf("%d\n", a);

    char arr[] = "Hello";
    int length = sizeof(arr)/sizeof(arr[0]);
    change_arr(arr, length);
    printf("arr: %s\n", arr);

    char *arr1 = change_arr_char(arr);
    printf("arr1: %s\n", arr1);


    char *arr2;
    char arr3[5] = "Hello";
    arr2 = arr3;
    change_arr1(arr2);
    printf("arr2: %s\n", arr2);
}

// q2. set breakpoint at int a = 5 and then walkthrough

// q3. need to use pointers to the array, and when passed to function, only preserves address to the first char, so need to +1 to change other chars
        // in python, simply change the entire array as a global and it automatically changes in the memory table

// p_a[1] = 'b'