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
#include <time.h>
#define MAX_QUEUE_SIZE 5

typedef struct {
    int id;
    int arrival_time;
    int service_time;
} element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
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

// duo
int main(void) {
    int minutes = 60;
    int total_wait = 0;
    int total_customers = 0;
    int service_time = 0;
    int service_customer;
    int service_time2 = 0;
    int service_customer2;
    QueueType queue;
    init_queue(&queue);
    srand(time(NULL));

    for (int clock = 0; clock < minutes; clock++) {
        printf("Current Time=%d\n", clock);
        if ((rand() % 10) < 3) {
            element customer;
            customer.id = total_customers++;
            customer.arrival_time = clock;
            customer.service_time = rand() % 3 + 1;
            enqueue(&queue, customer);
            printf("Customer %did, coming %dminutes. Duration=%dminutes\n", customer.id, customer.arrival_time, customer.service_time);
        }
        if (service_time > 0) {
            printf("Taking care of customer %d.\n", service_customer);
            service_time--;
        }
        else {
            if (!is_empty(&queue)){
                element customer = dequeue(&queue);
                service_time = customer.service_time;
                service_customer = customer.id;
                printf("%d Customer starts at %d minutes. Wait time was %d minutes.\n", customer.id, clock, clock - customer.arrival_time);
                total_wait += clock - customer.arrival_time;
            }
        }

        if (service_time2 > 0) {
            printf("DESK 2: Taking care of customer %d.\n", service_customer2);
            service_time2--;
        }
        else {
            if (!is_empty(&queue)){
                element customer = dequeue(&queue);
                service_time2 = customer.service_time;
                service_customer2 = customer.id;
                printf("DESK 2: %d Customer starts at %d minutes. Wait time was %d minutes.\n", customer.id, clock, clock - customer.arrival_time);
                total_wait += clock - customer.arrival_time;
            }
        }
    }
    printf("Total Wait Time: %d", total_wait);
    return 0;
}

// solo
// int main(void) {
//     int minutes = 60;
//     int total_wait = 0;
//     int total_customers = 0;
//     int service_time = 0;
//     int service_customer;
//     QueueType queue;
//     init_queue(&queue);
//     srand(time(NULL));

//     for (int clock = 0; clock < minutes; clock++) {
//         printf("Current Time=%d\n", clock);
//         if ((rand() % 10) < 3) {
//             element customer;
//             customer.id = total_customers++;
//             customer.arrival_time = clock;
//             customer.service_time = rand() % 3 + 1;
//             enqueue(&queue, customer);
//             printf("Customer %did, coming %dminutes. Duration=%dminutes\n", customer.id, customer.arrival_time, customer.service_time);
//         }
//         if (service_time > 0) {
//             printf("Taking care of customer %d.\n", service_customer);
//             service_time--;
//         }
//         else {
//             if (!is_empty(&queue)){
//                 element customer = dequeue(&queue);
//                 service_time = customer.service_time;
//                 service_customer = customer.id;
//                 printf("%d Customer starts at %d minutes. Wait time was %d minutes.\n", customer.id, clock, clock - customer.arrival_time);
//                 total_wait += clock - customer.arrival_time;
//             }
//         }
//     }
//     printf("Total Wait Time: %d", total_wait);
//     return 0;
// }
