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

ListNode* search_list(ListNode *head, element x) {
    // for (ListNode *p = head; p != NULL; p = p->link) {
    //     if (p->data == x) {
    //         return p;
    //     }
    // }

    ListNode *p = head;
    while (p != NULL) {
        if (p->data == x) return p;
        p = p->link;
    }
    return NULL; //failed
}

ListNode* concat_list(ListNode *head1, ListNode *head2) {
    if (head1 == NULL) return head2;
    else if (head2 == NULL) return head1;
    else {
        ListNode *p;
        p = head1;
        while (p->link != NULL) {            
            p = p->link;
        }
        p->link = head2;
        return head1;
    }
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

    head2 = insert_first(head2, 10);
    head2 = insert_first(head2, 20);
    print_list(head2);

    ListNode *total = concat_list(head1, head2);
    print_list(total);
    return 0;

}