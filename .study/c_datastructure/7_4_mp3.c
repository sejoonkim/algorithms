#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct DListNode {
    struct DListNode *llink, *rlink;
    element data;
} DListNode;

DListNode* current;

void init(DListNode *phead) {
    phead->rlink = phead;
    phead->llink = phead;
}

void print_dlist(DListNode *phead) {
    DListNode *p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        if (p == current)
            printf("<-| #%s# |->", p->data);
        else
            printf("<-| %s |->", p->data);
    }
    printf("\n");
}

void dinsert(DListNode *before, element data) {
    DListNode *node = (DListNode*)malloc(sizeof(DListNode));
    strcpy(node->data, data);
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
    char ch;
    DListNode *head = (DListNode*)malloc(sizeof(DListNode));
    init(head);

    dinsert(head, "Mamamia");
    dinsert(head, "Dancing Queen");
    dinsert(head, "Fernando");

    current = head->rlink;
    print_dlist(head);

    do {
        printf("\ninput(<, >, q): ");
        ch = getchar();
        if (ch == '<') {
            current = current->llink;
            if (current == head) 
                current = current->llink;
        }
        else if (ch == '>') {
            current = current->rlink;
            if (current == head)
                current = current->rlink;
        }
        print_dlist(head);
        getchar();
    } while (ch != 'q');
    free(head);
    return 0;
}