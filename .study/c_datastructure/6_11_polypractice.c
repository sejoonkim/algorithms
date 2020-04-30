/*
Implement with header node
1. ListNode
2. ListType
3. error
4. create
5. insert_last
6. poly_add
7. poly_print
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ListNode {
    int coef;
    int expon;
    struct ListNode *link;
} ListNode;

typedef struct ListType {
    int size;
    ListNode *head;
    ListNode *tail;
} ListType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListType* create() {
    ListType *plist = (ListType*)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = NULL;
    plist->tail = NULL;
    return plist;
}

void insert_last(ListType *plist, int coef, int expon) {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) error("Memory Allocation Error");
    newNode->coef = coef;
    newNode->expon = expon;
    newNode->link = NULL;

    // check if list is empty
    // if empty then set te head and tail to newnode
    // else only set tail to now node
    if (plist->tail == NULL) {
        plist->head = plist->tail = newNode;
    }
    else {
        plist->tail->link = newNode; // link the previous last element to new last element
        plist->tail = newNode; // change the tail pointer pointing location
    }
    plist->size++;
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
    ListNode* a = plist1->head;
    ListNode* b = plist2->head;
    int sum;

    while (a && b) { // while a and b are not NULL
        if (a->expon == b->expon) {
            sum = a->coef + b->coef;
            if (sum != 0) insert_last(plist3, sum, a->expon);
            a = a->link;
            b = b->link;
        }
        else if (a->expon < b->expon) {
            insert_last(plist3, b->coef, b->expon);
            b = b->link;
        }
        else {
            insert_last(plist3, a->coef, a->expon);
            a = a->link;
        }
    }

    for (; a != NULL; a = a->link) {
        insert_last(plist3, a->coef, a->expon);        
    }

    for (; b != NULL; b = b->link) {
        insert_last(plist3, b->coef, b->expon);        
    }
}

void poly_print(ListType *plist) {
    ListNode *p = plist->head;

    printf("Polynomial = ");
    for (; p; p = p->link) {
        printf("%d^%d + ", p->coef, p->expon);
    }
    printf("\n");
}

double poly_eval(ListType *plist, double x) {
    double sum = 0.0;
    for(ListNode *p = plist->head; p != NULL; p = p->link) {
        double num = p->coef * pow(x, p->expon);
        sum += num;
    }
    return sum;
}

int main(void) {
    ListType *list1, *list2, *list3;

    list1 = create();
    list2 = create();
    list3 = create();
    
    insert_last(list1, 3, 6);
    insert_last(list1, 7, 3);
    insert_last(list1, 2, 2);
    insert_last(list1, -9, 0);

    insert_last(list2, -2, 6);
    insert_last(list2, -4, 4);
    insert_last(list2, 6, 2);
    insert_last(list2, 6, 1);
    insert_last(list2, 1, 0);

    poly_print(list1);
    poly_print(list2);

    poly_add(list1, list2, list3);
    poly_print(list3);

    printf("%f", poly_eval(list3, 1.2));

    free(list1); free(list2); free(list3);
    return 0;
}