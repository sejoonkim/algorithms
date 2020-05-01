#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
    struct DListNode *llink, *rlink;
    element data;
} DListNode;

void init(DListNode *phead) {
    phead->rlink = phead;
    phead->llink = phead;
}

void print_dlist(DListNode *phead) {
    DListNode *p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        printf("<-| |%d| |-> ", p->data);
    }
    printf("\n");
}

void dinsert(DListNode *before, element data) {
    DListNode *node = (DListNode*)malloc(sizeof(DListNode));
    node->data = data;
    node->llink = before;
    node->rlink = before->rlink;
    before->rlink->llink = node;
    before->rlink = node;
}

void ddelete(DListNode *head, DListNode *removed) {
    if (removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

int main(void) {
    DListNode *head = (DListNode*)malloc(sizeof(DListNode));
    init(head);
    printf("Additional Stages\n");
    for (int i = 0; i < 5; i++) {
        dinsert(head, i);
        print_dlist(head);
    }
    printf("\nDelete Stage\n");
    for (int i = 0; i < 5; i++) {
        print_dlist(head);
        ddelete(head, head->rlink);
    }
    free(head);
    return 0;
}