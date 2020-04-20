/*
- declare StackType
    - typedef
    - init_stack
    - delete
    - is_empty
    - is_full
    - push
    - pop
    - peek
- infix to postfix
    - infix_to_postfix
        - switch
            - case (operators)
                - check is_empty and the order of operations ch < peek(&s)
                    - pop all operators
                - push ch
            - case '('
                - push all and break
            - case ')'
                - top_op = pop()
                - while top_op != ')'
                    - print top_op
                    - top_op = pop()
                - break;
            - default
                - print
        - while stack is not empty
            - print remaining operators

- postfix calculation
    - calculate
        - for the length of the string
            - if (not operator) push to stack
            - else
                op2 = pop()
                op1 = pop()
                - switch  
                - case + push(&s, op1 + op2) break;
                - case -
                - case *
                - case /

    return pop(&s);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

typedef int element;
typedef struct {
    element *data;
    int *num;
    int capacity;
    int top;
} StackType;

// for saving results from infix to postfix

void init_stack(StackType *s) {
    s->capacity = 1;
    s->top = -1;
    s->data = (element *)malloc(s->capacity * sizeof(element));
    if (s->data == NULL){
        fprintf(stderr, "No more memory");
        exit(1);
    }
}

void delete(StackType *s) {
    free(s);
}

int is_empty(StackType *s) {
    return (s->top == -1);
}

int is_full(StackType *s) {
    return (s->top == s->capacity - 1);
}

void push(StackType *s, element item) {
    if (is_full(s)) {
        s->capacity *= 2;
        s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
        if (s->data == NULL) {
            fprintf(stderr, "No more memory.");
            exit(1);
        }
    }
    s->data[++(s->top)] = item;
}

element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Empty Stack!");
        exit(1);
    }
    return s->data[(s->top)--];
}

element peek(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Empty Stack!");
        exit(1);
    }
    return s->data[s->top];
}

int pri(char op) {
    switch(op) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}


void infix_to_postfix(char exp[], char postfix[], int *postfix_index) {
    StackType s;
    init_stack(&s);

    int i = 0, len = strlen(exp);
    char ch, top_op;

    for (i = 0; i < len; i++) {
        ch = exp[i];
        switch (ch) {
            case '+': case '-': case '*': case '/':
                while(!is_empty(&s) && pri(ch) <= pri(peek(&s))) {
                    // printf("%c", pop(&s));
                    postfix[(*postfix_index)++] = pop(&s);
                    if (exp[i+1] != '+' || exp[i+1] != '-' || exp[i+1] != '*' || exp[i+1] != '/' || exp[i+1] != ')' || exp[i+1] != '\0') {
                    postfix[(*postfix_index)++] = ' '; // insert empty
                    }
                }
                push(&s, ch);
                break;
            case '(':
                push(&s, ch);
                break;
            case ')':
                top_op = pop(&s);
                while(top_op != '(') {
                    // printf("%c", top_op);
                    postfix[(*postfix_index)++] = top_op;
                    if (exp[i+1] != '+' || exp[i+1] != '-' || exp[i+1] != '*' || exp[i+1] != '/' || exp[i+1] != ')' || exp[i+1] != '\0') {
                    postfix[(*postfix_index)++] = ' '; // insert empty
                    }
                    top_op = pop(&s);
                }
                break;
            default:
                // printf("%c", ch);
                postfix[(*postfix_index)++] = ch;
                if (exp[i+1] == '+' || exp[i+1] == '-' || exp[i+1] == '*' || exp[i+1] == '/' || exp[i+1] == ')' || exp[i+1] == '\0') {
                    postfix[(*postfix_index)++] = ' '; // insert empty
                }
        }
    }
    while(!is_empty(&s)) {
        // printf("%c", pop(&s));
        postfix[(*postfix_index)++] = pop(&s);
        postfix[(*postfix_index)++] = ' ';
    }
}


// - postfix calculation
//     - calculate
//         - for the length of the string
//             - if (not operator) push to stack
//             - else
//                 op2 = pop()
//                 op1 = pop()
//                 - switch  
//                 - case + push(&s, op1 + op2) break;
//                 - case -
//                 - case *
//                 - case /

//     return pop(&s);

element postfix_calc(char exp[]) {
    StackType s;
    int i, len = strlen(exp);
    int op1, op2, value, num_val;
    int count = 0;
    char ch;
    init_stack(&s);

    for (i = 0; i < len; i++) {
        ch = exp[i];
        if (ch >= '0' && ch <= '9') {
            while(exp[i + count] != ' ') {
                count++;
            }
            num_val = atoi(&exp[i]);
            i += count;
            count = 0;
            push(&s, num_val);
        }
        else {
            if (ch != ' ') {
                op2 = pop(&s);
                op1 = pop(&s);
                switch(ch) {
                    case '+': push(&s, op1 + op2); break;
                    case '-': push(&s, op1 - op2); break;
                    case '*': push(&s, op1 * op2); break;
                    case '/': push(&s, op1 / op2); break;
                }
            }
        }
    }
    return pop(&s);
}


int main(void) {
    char *postfix = (char*)malloc(1000*sizeof(char));
    int postfix_index = 0;
    int result;
    char *p = "(20+30)*40+90";
    printf("%s\n", p);
    infix_to_postfix(p, postfix, &postfix_index);
    printf("%s", postfix);
    printf("\n");

    char *p2 = "23+4*9+";
    result = postfix_calc(postfix);
    printf("%d", result);
    return 0;
}