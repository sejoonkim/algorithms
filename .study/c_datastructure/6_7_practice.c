/*
    
*/  
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
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
    plist->head = plist->tail = NULL;
    return plist;
}

void insert_last(ListType* plist, element item) {
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
        printf("%d->", p->data);
    }
    printf("NULL\n");
}

int add_list(ListType *plist) {
    int sum = 0;
    for (ListNode *p = plist->head; p != NULL; p = p->link) {
        sum += p->data;
    }
    return sum;
}

int get_entry(ListType *plist, element number) {
    int index = 1;
    for (ListNode *p = plist->head; p->link != NULL; p = p->link) {
        if (p->data == number) {
            return index;
        }
        index++;
    }
    return -1; // failed
}

void delete(ListType *plist, element number) {
    ListNode *prev, *removed;
    for (ListNode *p = plist->head; p != NULL; p = prev->link) {
        if (p->data == number) {
            removed = p;
            prev->link = removed->link;
            free(removed);
            continue;
        }
        prev = p;
    }
}

int how_many(ListType *plist, element number) {
    int count = 0;
    for (ListNode *p = plist->head; p != NULL; p = p->link) {
        if (p->data == number) {
            count++;
        }
        
    }
    return count; // failed
}

int main(void) {
    ListType *plist;
    plist = create();
    int loop_num;
    printf("Number of Nodes: ");
    scanf("%d", &loop_num);

    for (int i = 1; i <= loop_num; i++) {
        element data;
        printf("Node %d Data: ", i);
        scanf("%d", &data);
        insert_last(plist, data);
    }
    print_list(plist);
    printf("Length: %d\n", plist->size);
    printf("Sum: %d\n", add_list(plist));

    int number;
    printf("Which number to delete?: ");
    scanf("%d", &number);
    delete(plist, number);
    // printf("Found at %d\n", get_entry(plist, number));
    // printf("How many %d\n", how_many(plist, number));
    print_list(plist);
    
    return 0;
}