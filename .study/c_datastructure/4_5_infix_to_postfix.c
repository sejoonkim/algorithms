#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef int element;
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

element peek(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    else {
        return s->data[s->top];
    }
}

int pri(char op) {
    switch (op) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

void infix_to_postfix(char exp[]) {
    StackType s;
    init_stack(&s);
    int i = 0, len = strlen(exp);
    char ch, top_op;

    for (i = 0; i < len; i++) {
        ch = exp[i];
        switch (ch) {
            case '+': case '-': case '*': case '/':
                while (!is_empty(&s) && pri(ch) <= pri(peek(&s))) {
                    printf("%c", pop(&s));
                }
                push(&s, ch);
                break;

            case '(':
                push(&s, ch);
                break;

            case ')':
                top_op = pop(&s);
                while (top_op != '(') {
                    printf("%c", top_op);
                    top_op = pop(&s);
                }
                break;
            default:
                printf("%c", ch);
        }
    }
    while (!is_empty(&s)) {
        printf("%c", pop(&s));
    }
}

int main(void) {
    char *s = "5+6/3+2-5*6/2";
    printf("infix: %s\n", s);
    printf("postfix: ");
    infix_to_postfix(s);
    printf("\n");
    return 0;
}