#include <stdio.h>
#include <stdlib.h>

int main(){
    // a.
    //char * ptr = 0;
    //*ptr = 1;
    // causes bad access --> seg fault?

    // b. (can't do, not on ECF)

    // c.   --> rest on ECF
    FILE *fp;
    fp = fopen("a.txt", "r");

    // d. 
    if (fp == NULL){
        printf("Error");
    }
    fclose(fp);

    // e. ??

    //char[3] = 'hel';
    // char[1000] = 'h'

}