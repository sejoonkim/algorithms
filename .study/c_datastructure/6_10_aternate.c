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

typedef struct ListNode {
    int data;
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

void insert_last(ListType *plist, int data) {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) error("Memory Allocation Error");
    newNode->data = data;
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

void print_list(ListType *plist) {
    for (ListNode *p = plist->head; p != NULL; p = p->link) {
        printf("%d->", p->data);
    }
    printf("NULL\n");
}

void alternate(ListType *plist1, ListType *plist2, ListType *plist3) {
    int index = 0;
    ListNode *p = plist1->head, *q = plist2->head;
    while (q != NULL) {
        if (!(index & 1)) {
            insert_last(plist3, p->data);
            p = p->link;
            index++;
        }
        else {
            insert_last(plist3, q->data);
            q = q->link;
            index++;
        }
    }

}

void merge(ListType *plist1, ListType *plist2, ListType *plist3) {
    ListNode *p = plist1->head, *q = plist2->head;
    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            insert_last(plist3, p->data);
            p = p->link;
        }
        else {
            insert_last(plist3, q->data);
            q = q->link;
        }
    }
    while (p != NULL) {
        insert_last(plist3, p->data);
        p = p->link;
    }
    while (q != NULL) {
        insert_last(plist3, q->data);
        q = q->link;
    }

}

void split(ListType *plist1, ListType *plist2, ListType *plist3) {
    int index = 0;
    ListNode *p = plist1->head, *q = plist2->head, *r = plist3->head;
    while (p != NULL) {
        if (!(index & 1)) {
            insert_last(plist2, p->data);
        }
        else {
            insert_last(plist3, p->data);
        }
        p = p->link;
        index++;
    }

}

int main(void) {
    ListType *list1, *list2, *list3, *list4, *list5;

    list1 = create();
    list2 = create();
    list3 = create();
    list4 = create();
    list5 = create();
    
    insert_last(list1, 1);
    insert_last(list1, 4);
    insert_last(list1, 5);

    insert_last(list2, 8);
    insert_last(list2, 9);
    insert_last(list2, 10);

    print_list(list1);
    print_list(list2);

    merge(list1, list2, list3);
    print_list(list3);
    split(list3, list4, list5);
    print_list(list4);
    print_list(list5);

    free(list1); free(list2); free(list3);
    return 0;
}