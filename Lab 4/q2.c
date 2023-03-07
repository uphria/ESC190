#include <stdio.h>
#include <stdlib.h>

int my_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    if(str[i] == "-"){
        sign = -1;
        i++;
    }
    int result = 0;
    while(str[i] >= '0' && str[i] <= '9'){
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}

void open_file(char *file){
    FILE *fp;
    fp = fopen("a.txt", "r");

    // d. 
    if (fp == NULL){
        printf("Error");
        fclose(fp);
        return 1;
    }

    char myString[100];
    int res = 0;
    while(fgets(myString, 100, fp)) {
        res += my_atof(myString);
    }
    
    fclose(fp);
}

double my_atof(const char *str){
    int sign = 1;
    if(*str == '-'){
        sign = -1;
        str++;
    }
    double integer_part = 0;
    while (*str != '.'){
        integer_part = 10*integer_part + (*str-'0');
        str ++;
    }
    str++;
    double fractional_part = 0;
    double cur_pow10 = 0.1;
    while(*str != '\0' && *str != '\n'){
        fractional_part += (*str - '0')*cur_pow10;
        cur_pow10*=0.1;
        str++;
    }
    return sign*(integer_part+fractional_part);
}


// In C, Without using atof or any of the scanf family of functions, write a program that reads a text file that lists several (not necessarily 3) constants formatted similarly to the following:

int main(void){
    
}