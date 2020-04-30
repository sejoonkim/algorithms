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

void print_list(ListNode *head) {
    for (ListNode *p = head; p != NULL; p = p->link) {
        printf("%d->", p->data);
    }
    printf("NULL \n");
}

int main(void) {
    ListNode *head = NULL;

    for (int i = 0; i < 5; i++) {
        head = insert_first(head, i);
        print_list(head);
    }

    printf("----------NewNode at index 3 = %d----------\n length %d \n", get_entry(head, 3), get_length(head));


    for (int i = 0; i < 5; i++) {
        head = delete_first(head);
        print_list(head);
    }
    return 0;

}