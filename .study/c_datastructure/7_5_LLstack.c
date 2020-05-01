#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackNode {
    element data;
    struct StackNode *link;
} StackNode;

typedef struct LinkedStackType {
    StackNode *top;
} LinkedStackType;

void init(LinkedStackType *s) {
    s->top = NULL;
}

int is_empty(LinkedStackType *s) {
    return s->top == NULL;
}

int is_full(LinkedStackType *s) {
    return 0;
}

void push(LinkedStackType *s, element item) {
    StackNode *node = (StackNode*)malloc(sizeof(StackNode));
    node->data = item;
    node->link = s->top;
    s->top = node;
}

void print_stack(LinkedStackType *s) {
    for (StackNode *p = s->top; p != NULL; p = p->link) {
        printf("%d->", p->data);
    }
    printf("NULL \n");
}

element delete(LinkedStackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Empty Stack");
        exit(1);
    }
    else {
        StackNode *temp = s->top;
        int data = temp->data;
        s->top = s->top->link;
        free(temp);
        return data;
    }
}

element peek(LinkedStackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Empty Stack");
        exit(1);
    }
    else {
        int data = s->top->data;
        return data;
    }    
}

int main(void) {
    LinkedStackType s;
    init(&s);
    push(&s, 1); print_stack(&s);
    push(&s, 2); print_stack(&s);
    push(&s, 4); print_stack(&s);
    push(&s, 5); print_stack(&s);
    delete(&s); print_stack(&s);
    delete(&s); print_stack(&s);
    delete(&s); print_stack(&s);


    return 0;
}