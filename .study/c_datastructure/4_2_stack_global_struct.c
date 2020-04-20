#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_STRING 1000
// typedef int element;
// element stack[MAX];

typedef struct {
    int student_np;
    char name[MAX_STRING];
    char address[MAX_STRING];
} element;
element stack[MAX_SIZE];
int top = -1;

int is_empty() {
    // if (top == -1) return 1;
    // else return 0;
    return (top == -1);
}

int is_full() {
    return (top == MAX_SIZE - 1);
}

void push(element item) {
    if (is_full()) {
        fprintf(stderr, "Stack is full\n");
        return;
    }
    else {
        stack[++top] = item;
    }
}

element pop() {
    if (is_empty()) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    else {
        return stack[top--];
    }
}

element peek() {
    if (is_empty()) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    else {
        return stack[top];
    }
}

int main(void) {
    //push(1);
    // push(2);
    // push(3);
    // printf("%d\n", pop());
    // printf("%d\n", pop());
    // printf("%d\n", pop());

    element in = {20123022, "Kim", "Seoul"};
    element out;
    push(in);
    out = pop();

    printf("%d", out.student_np);
    printf("%s", out.name);
    printf("%s", out.address);
    return 0;
}

