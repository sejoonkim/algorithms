/*
start - 17 : 41
  end - 

- Queue ADT
    - initialize
    - is_full
    - is_empty
    - enqueue
    - dequeue
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
  int front;
  int rear;
  element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char *message) {
  fprintf(stderr, "%s\n", message);
  exit(1);
}

void queue_print(QueueType *q) {
  for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
    if (i <= q->front || i > q->rear)
      printf("  | ");
    else
      printf("%d | ", q->data[i]);
  }
  printf("\n");
}

void queue_init(QueueType *q) {
  q->front = -1;
  q->rear = -1;
}

int is_full(QueueType *q) {
  if (q->rear == MAX_QUEUE_SIZE - 1) {
    return 1;
  }
  else return 0;
}

int is_empty(QueueType *q) {
  if (q->front == q->rear) return 1;
  else return 0;
}

void enqueue(QueueType *q, int item) {
  if (is_full(q)) {
    error("Queue is full.");
    return;
  }
  q->data[++(q->rear)] = item;
}

int dequeue(QueueType *q) {
  if (is_empty(q)) {
    error("Queue is empty.");
    return -1;
  }
  int item = q->data[++(q->front)];
  return item;
}

int main(void) {
  int item = 0;
  QueueType q;

  queue_init(&q);

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);

  queue_print(&q);

  item = dequeue(&q);
  queue_print(&q);
  return 0;
}