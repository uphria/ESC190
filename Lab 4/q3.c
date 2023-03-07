#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student1{
    char name[3];
    int age;
} student1;

void change_name1_wrong(student1 s){
    s.name[0] = 'b';
}
// no equivalent in Python since would have to go into student[0] and then maken student[0][0] = 'b'

void change_name1_right_a(student1 *p_s){
    p_s->name[0] = 'b';
}
// can't pass address of student in Python

void change_name1_right_b(student1 *p_s){
    strcpy(p_s->name, "b");
}
// can't pass address in Python

void change_like_py(char *new_name, student1 *p_s){
    int i = 0;
    while (*(new_name+i) != '\0'){
      p_s->name[i] = *(new_name+i);
      i++;
    }
}

int main(){
    student1 s = {"ab", 3};
    char new_name[3] = "cd";
    change_like_py(new_name, &s);
    printf("%s\n", s.name);
}

// C can't store types together, can't have shallow copies, only use pointers
// in python, strings are immutable --> all examples are trying to change the string