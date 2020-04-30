/*
    
*/  
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int age;
    float height;
} element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;
typedef struct ListType {
    ListNode *head, *tail;
    int size;
} ListType;

ListType* create() {
    ListType* plist = (ListType*)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

void add_list(ListType *plist, element item) {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = item;
    newNode->link = NULL;
    if (plist->tail == NULL) {
        plist->head = plist->tail = newNode;
    }
    else {
        plist->tail->link = newNode;
        plist->tail = newNode;
    }
    plist->size++;
}

void print_list(ListType *plist) {
    for (ListNode *p = plist->head; p != NULL; p = p->link) {
        printf("%s, %d, %.1f\n", p->data.name, p->data.age, p->data.height);
    }
}

int main(void) {
    ListType *plist = create();
    element item1 = {"kim", 34, 1.7};
    element item2 = {"park", 27, 1.2};
    element item3 = {"lee", 48, 1.4};

    add_list(plist, item1);
    add_list(plist, item2);
    add_list(plist, item3);
    
    print_list(plist);

    return 0;
}