#include <stdio.h>

void set_int1(int x) {
    x = 42;
}

void set_int2(int *p_x) {
    *p_x = 42;
}

int main(){
    int a = 5;
    set_int1(a);
    printf("%d\n", a);      // prints 5

    int b = 6;
    set_int2(&b);
    printf("%d\n", b);      // prints 42
}

// int1 takes a copy of x and then sets the copy of x in the locals frame to 42. This has no effect on the x in the main frame
// int2 takes the address of x and then changes the value at the address of x. This changes the x in the main frame to 42