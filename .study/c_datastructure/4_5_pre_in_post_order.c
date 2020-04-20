#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
    element *data;
    int capacity;
    int top;
} StackType;

void init_stack(StackType *s) {
    s->top = -1;
    s->capacity = 1;
    s->data = (element *)malloc(s->capacity * sizeof(element));
    if (s->data == NULL){
        fprintf(stderr, "No more memory");
        exit(1);
    }
}

int is_empty(StackType *s) {
    return (s->top == -1);
}

int is_full(StackType *s) {
    return (s->top == s->capacity - 1);
}

void delete(StackType *s) {
    free(s);
}

void push(StackType *s, element item) {
    if (is_full(s)) {
        s->capacity *= 2;
        s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
        if (s->data == NULL) {
            fprintf(stderr, "No more memory");
            exit(1);
        }
    }
    s->data[++(s->top)] = item;
}

element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack is empty!");
        exit(1);
    }
    else return s->data[(s->top)--];
}

int eval(char exp[]) {
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;
    StackType s;
    init_stack(&s);
    for (i = 0; i < len; i++) {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            value = ch - '0';
            push(&s, value);
        }
        else {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch) {
                case '+': push(&s, op1 + op2); break;
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}

int main(void) {
    char *p = "123*+";
    int result;
    result = eval(p);
    printf("result: %d", result);

    return 0;
}