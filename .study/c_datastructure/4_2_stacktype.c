#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_STRING 1000

typedef int element;
// element stack[MAX];

// typedef struct {
//     int student_np;
//     char name[MAX_STRING];
//     char address[MAX_STRING];
// } element;
// element stack[MAX_SIZE];

typedef struct {
    element data[MAX_SIZE];
    int top;
} StackType;
// int top = -1;

void init_stack(StackType *s) {
    s->top = -1;
}

int is_empty(StackType *s) {
    // if (top == -1) return 1;
    // else return 0;
    return (s->top == -1);
}

int is_full(StackType *s) {
    return (s->top == MAX_SIZE - 1);
}

void push(StackType *s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "Stack is full\n");
        return;
    }
    else {
        s->data[++s->top] = item;
    }
}

element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    else {
        return s->data[s->top--];
    }
}

element peek(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    else {
        return s->data[s->top];
    }
}

int main(void) {
    // Dynamic memory allocation;
    StackType *s = (StackType*)malloc(sizeof(StackType));
    StackType *s_new = (StackType*)malloc(sizeof(StackType));

    // Static memory allocation
    //StackType t;

    init_stack(s);
    init_stack(s_new);
    push(s, 1);
    push(s, 2);
    push(s, 3);

    push(s_new, peek(s));
    printf("%d\n", pop(s));
    push(s_new, peek(s));
    printf("%d\n", pop(s));
    push(s_new, peek(s));
    printf("%d\n", pop(s));

    printf("%d\n", pop(s_new));
    printf("%d\n", pop(s_new));
    printf("%d\n", pop(s_new));
    free(s);

    // init_stack(&t);
    // push(&t, 1);
    // printf("%d\n", pop(&t));
    return 0;
}

