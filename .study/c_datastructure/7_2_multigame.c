/*
    
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];

typedef struct ListNode {
    struct ListNode *link;
    element data;
} ListNode;

void print_list(ListNode* head) {
    ListNode *p;

    if (head == NULL) return;
    p = head->link;
    do {
        printf("%s->", p->data);
        p = p->link;
    } while (p != head);
    printf("%s->", p->data);
}

ListNode* insert_first(ListNode *head, element data) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    strcpy(node->data, data);
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

ListNode* insert_last(ListNode *head, element data) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    strcpy(node->data, data);
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

int main(void) {
    ListNode *head = NULL;

   
    head = insert_first(head, "KIM");

    head = insert_first(head, "Park");
    head = insert_first(head, "Choi");
    print_list(head);
    return 0;
}