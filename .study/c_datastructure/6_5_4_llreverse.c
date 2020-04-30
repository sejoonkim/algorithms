/*
1. insert_first()
2. insert()
3. delete_first()
4. delete()
5. print_list()
*/
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}


ListNode* insert_first(ListNode *head, element value) {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = value;
    newNode->link = head;
    head = newNode;
    return head;
}

ListNode* insert(ListNode *head, ListNode *pre, element value) {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = value;
    newNode->link = pre->link;
    pre->link = newNode;
    return head;
}

ListNode* delete_first(ListNode *head) {
    ListNode *removed;
    if (head == NULL) return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode* delete(ListNode *head, ListNode *pre) {
    if (head == NULL) return NULL;
    ListNode *removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

element get_entry(ListNode *head, int index) {
    ListNode *element_at_index = head;
    for (int i = 1; i < index; i++) {
        element_at_index = element_at_index->link;
    }
    return element_at_index->data;
}

int get_length(ListNode *head) {
    int length = 0;
    for (ListNode *p = head; p != NULL; p = p->link) {
        length++;
    }
    return length;
}

ListNode* reverse(ListNode *head) {
    ListNode *p, *q, *r;

    p = head;
    q = NULL;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    return q;
}

void print_list(ListNode *head) {
    for (ListNode *p = head; p != NULL; p = p->link) {
        printf("%d->", p->data);
    }
    printf("NULL \n");
}

int main(void) {
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;

    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    print_list(head1);

    head2 = reverse(head1);
    print_list(head2);
    return 0;

}