#include <stdio.h>

int len_str(char *ptr){
    int length = 0;
    while (*(ptr+length) != '\0'){
        length++;
    }
    return length+1;
} 

int main(){
    char str[] = "sHello";
    char *ptr;
    ptr = str;
    int length = len_str(ptr);
    printf("%d", length);
    return 0;
}

// O(n), where n is the length of the string