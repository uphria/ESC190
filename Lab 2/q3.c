#include <stdio.h>

// base case is smallest case??
// recursion increases??
// have to use increase for first non-equal element though...
// case where len(s1) !- len(s2)

int strcmp_rec(char* s1, char* s2){
    if (*s1 > *s2){
        return 1;
    }
    if (*s1 < *s2){
        return -1;
    }
    if (*s1 == '\0' && *s2 == '\0'){
        return 0;
    }
    return strcmp_rec(s1+1, s2+1);
}

int main(){
    char *s1 = "Hello";
    char *s2 = "Hekko";
    int res = strcmp_rec(s1, s2);
    printf("%d", res);
    return 0;
}

// s1 == s2 True if they point to the same location
// *s1 == *s2 tells you if the elements located at address *s1 and address *s2 are the same
// strcmp(s1, s2) tells you which string is "greater" or "lesser", or if they are equal
    // looks at all the elements