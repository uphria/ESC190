#include <stdio.h>
#include <string.h>

char *strcat_i(char *dest, char *source){
    int i = strlen(dest);
    int j = 0;
    while (source[j] != '\0'){
        dest[i] = source[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}

char *strcat_pointer(char *source, char *dest){
    int i = strlen(dest);
    int j = 0;
    for (j = 0; j < strlen(source)-1; i++){
        *(dest+i) = *(source+j);
    }
    *(dest+i) = '\0';
    return dest;
}

int main(){
    char s1[100] = "hello";
    char s2[] = "world";
    strcat_i(s1, s2);
    for (int i = 0; i<strlen(s1); i++){
        printf("%c", s1[i]);
    }
    printf("\n");

    char s3[100] = "hello";
    char s4[] = "world";
    strcat_i(s3, s4);
    for (int j = 0; j<strlen(s3); j++){
        printf("%c", s3[j]);
    }
    printf("\n");

    return 0;
}