/*
    
*/
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;



int main(void) {
    ListNode *head = NULL;
    head = (ListNode*)malloc(sizeof(ListNode));
    head->data = 10;
    head->link = NULL;
    
    ListNode *Node;
    Node = (ListNode*)malloc(sizeof(ListNode));
    Node->data = 20;
    Node->link = NULL;

    head->link = Node;

    return 0;
}