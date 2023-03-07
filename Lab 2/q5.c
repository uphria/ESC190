#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int my_atoi(char *str){
    int res = 0;
    int neg = 1;
    for (int i = 0; i < strlen(str); i++){
        if (isdigit(*(str+i))){
          res = res*10 + *(str+i) - '0';
        } 
        if (*(str+i) == '-'){
          neg = -1;
        }
    }
    return res*neg;
}

int main(){
    char *str = "dog";
    int atoi_res = my_atoi(str);
    printf("function atoi: %d\n", atoi_res);
    int real_atoi = atoi(str);
    printf("real atoi: %d\n", real_atoi);

    char *str1;
    str1 = " -8995";
    int atoi_res1;
    atoi_res1 = my_atoi(str1);
    printf("function atoi: %d\n", atoi_res1);
    int real_atoi1;
    real_atoi1 = atoi(str1);
    printf("real atoi: %d\n", real_atoi1);
}