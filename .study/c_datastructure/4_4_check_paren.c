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

int check_matching(const char *in) {
    StackType s;
    char ch, open_ch;
    int i, n = strlen(in);
    init_stack(&s);

    for (i = 0; i < n; i++) {
        ch = in[i];
        switch (ch) {
            case '(': case '[': case '{':
                push(&s, ch);
                break;
            case ')': case ']': case '}':
                open_ch = pop(&s);
                if (open_ch == '(' && ch != ')' || open_ch == '[' && ch != ']' || open_ch == '{' && ch != '}')
                    return 0; // failed
                break;
        }
    }
    if (!is_empty(&s)) return 0; // remain in stack: failure
    return 1;   
}

int main(void) {
    char *p = "{ A[(i+1)]=0; )}";
    if (check_matching(p) == 1)
        printf("%s success\n", p);
    else
        printf("%s failure\n", p);
    
    return 0;
}