#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode {
    element data;
    struct QueueNode *link;
} QueueNode;

typedef struct LinkedQueueType {
    int size;
    QueueNode *front, *rear;
} LinkedQueueType;


void init(LinkedQueueType *q) {
    q->front = q->rear = 0;
}

int is_empty(LinkedQueueType *q) {
    return q->front == NULL;
}

int is_full(LinkedQueueType *q) {
    return 0;
}

void enqueue(LinkedQueueType *q, element item) {
    QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = item;
    node->link = NULL;
    if (is_empty(q)) {
        q->front = q->rear = node;
    }
    else {
        q->rear->link = node;
        q->rear = node;
    }
}

element dequeue(LinkedQueueType *q) {
    if (is_empty(q)) {
        fprintf(stderr, "Queue Empty.");
        exit(1);
    }
    QueueNode *node = q->front;
    element data = node->data;
    q->front = q->front->link;
    if (q->front == NULL) {
        q->rear == NULL;
    }
    free(node);
    return data;
}

void print_queue(LinkedQueueType *q) {
    for (QueueNode *p = q->front; p != NULL; p = p->link) {
        printf("%d->", p->data);
    }
    printf("NULL\n");
}
int main(void) {
    LinkedQueueType queue;
    init(&queue);

    enqueue(&queue, 1); print_queue(&queue);
    enqueue(&queue, 2); print_queue(&queue);
    enqueue(&queue, 3); print_queue(&queue);

    dequeue(&queue); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);

    return 0;
}