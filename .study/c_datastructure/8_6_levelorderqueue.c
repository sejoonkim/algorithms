/*
Circular Queue

1. init_queue
2. is_full
3. is_empty
4. enqueue
5. dequeue
6. print_queue
7. peek
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_QUEUE_SIZE 100

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

typedef TreeNode * element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} QueueType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q) {
    q->front = q->rear = 0;
}

int is_empty(QueueType *q) {
    return q->front == q->rear;
}

int is_full(QueueType *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void print_queue(QueueType *q) {
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType *q, element item) {
    if (is_full(q)) {
        error("Queue is full.");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q) {
    if (is_empty(q)) {
        error("Queue is empty.");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(QueueType *q) {
    if (is_empty(q)) {
        error("Queue is empty.");
    }
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void level_order(TreeNode *ptr) {
    QueueType q;
    init_queue(&q);

    // if empty tree, return
    if (ptr == NULL) return;
    enqueue(&q, ptr);

    // pop queue until empty
    while (!is_empty(&q)) {
        ptr = dequeue(&q);
        printf("%d->", ptr->data);
        if (ptr->left)
            enqueue(&q, ptr->left);
        if (ptr->right)
            enqueue(&q, ptr->right);
    }
}

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode *root = &n6;


int main(void) {
    printf("Levelorder=");
    level_order(root);
    printf("\n");
    return 0;
}
