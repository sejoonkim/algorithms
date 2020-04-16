#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentTag {
    char name[10];
    int age;
    double gpa;
} student;

int main(void) {
    student *s;
    s = (student*)malloc(sizeof(student));
    if(s == NULL) {
        fprintf(stderr, "No more memory");
        exit(1);
    }

    strcpy(s->name, "Brian");
    s->age = 10;
    s->gpa = 3.8;

    free(s);
    return 0;
}