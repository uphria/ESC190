#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student1{
    char name[200];
    char student_number[11];
    int year;
} student1; 

typedef struct student2{
    char *name;
    char *student_number;
    int year;
} student2;

// Q2
void print_stud1(student1 s){
    printf("%s\n%s\n%d\n", s.name, s.student_number, s.year);
}

// Q3a, b
void set_default_name(student1 *p_s){
    strcpy(p_s->name, "Default Student");
    p_s->year = 0;
}

//Q3b
void set_default_name_wrong(student1 s){
    strcpy(s.name, "Default Wrong Student");
    s.year = 0;
}
// verified, doesn't work
// changing year also doesn't work, same as Q2

//Q4
void create_block1(student1 **p_p_s, int n_students){
    *p_p_s = (student1 *)malloc(n_students*sizeof(student1));
    //(*p_p_s)->name = (char *)malloc(200*n_students*sizeof(char));
    //(*p_p_s)->student_number = (char *)malloc(11*n_students*sizeof(char));
    //(*p_p_s)->year = (int)malloc(n_students*sizeof(char));   
    // everything else is allocated memor
}

//Q5
void set_name(char *str, student1 *p_s){
    char str_199[200];
    int yes = 0;
    for (int i = 0; i < 200; i++){
      if (*(str+i) == '\0'){
        yes = 1;
        break;
      }   
    }
    if (yes == 1){
      strcpy(p_s->name, str);
    }  
    else{
      *(str+199) = '\0';
      strcpy(p_s->name, str);
    }
}

//Q6
void destroy_block1(student1 *p_s){
    //free(p_s->name);
    //free(p_s->student_number);
    //free(p_s->year);
    free(p_s);
}

//Q7
void create_block2(student2 **p_p_s, int n_students){
    *p_p_s = (student2 *)malloc(sizeof(student2)*n_students);
    for(int i = 0; i < n_students; i++){
        ((*p_p_s)+i)->name = 0;
        ((*p_p_s)+i)->student_number = 0;
    }
    // what does it mean to set both name and student_number to 0?
}

//Q8
void set_name2(student2 *p_s, char *str){
    int i = 0;
    int length = 0;
    char name_i[50];
    while (*(str+i) != '\0'){
        name_i[i] = *(str+i);
        length++;
        i++;
    }
    name_i[i] = '\0';
    p_s->name = (char *)malloc(length+1);
    strcpy(p_s->name, name_i); 
}

//Q9
void destroy_block2(student2 *p_s){
    free(p_s->name);
    free(p_s);
}

//Q10
void set_name_test2(student2 *s){
    strcpy(s->name, "Test Name");
    // when you pass a structure into the function, it creates a local copy of the structure that will be modified within, but there will be no effect outside the function
    // if you pass a pointer to a structure, it will use the pointer to midfy the structure in main, which has an effect
}

int main(){
    
    student1 s1;
    strcpy(s1.name, "Sarah Xu");
    strcpy(s1.student_number, "1234567890");
    s1.year = 1;
    /*print_stud1(s1);

    set_default_name(&s1);
    print_stud1(s1);

    s1.year = 1;
    set_default_name_wrong(s1);
    print_stud1(s1);

    student1 *p_s;
    create_block1(&p_s, 15);

    char *name_p;
    char name[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    name_p = name;
    set_name(name_p, &s1);
    print_stud1(s1);
    
    destroy_block1&p_s)
    */
    student2 *p_s2;
    create_block2(&p_s2, 3);
    //student2 p_s2i;
    //strcpy(p_s2i.name, "0");
    //strcpy(p_s2i.student_number, "0");

    char *in_name;
    char named[] = "Mary Poppins";
    in_name = named;
    set_name2(p_s2, in_name);
    printf("%s\n", p_s2->name);
    destroy_block2(p_s2);

    set_name_test2(p_s2);
    printf("%s\n", p_s2->name);
}