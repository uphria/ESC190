#include <stdio.h>
#include <stdlib.h>

void use_scanf(char **my_char, int *num_char){
    int n;
    printf("Number of characters: ");
    scanf(" %d", &n);
    *num_char = n;
    *my_char = (char *)malloc((n+1));
    for (int i = 0; i < n; i++){
        printf("Enter character %d: ", i);
        scanf(" %c", &(*(*my_char+i)));
    }
    *(*my_char+n) = '\0';
}

int main(){
    char *my_arr;
    int n;
    use_scanf(&my_arr, &n);

    for (int i = 0; i < n; i++){
        printf("%c", my_arr[i]);
    }
    free(my_arr);
    return 0;
}