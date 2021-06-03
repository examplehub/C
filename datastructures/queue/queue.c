#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE 5
typedef int ElemType;
typedef struct Queue {
    ElemType *base;
    int front; /* front pointer of queue */
    int rear; /* rear pointer of queue */
} Queue;

void initQueue(Queue *pQueue) {
    pQueue->base = malloc(sizeof(struct Queue) * MAX_SIZE);
    pQueue->front = pQueue->rear = 0;
}

bool isEmpty(Queue *pQueue) {
    return pQueue->rear == pQueue->front;
}

bool isFull(Queue *pQueue) {
    return pQueue->rear == MAX_SIZE;
}

int size(Queue *pQueue) {
    return pQueue->rear - pQueue->front;
}

bool enqueue(Queue *pQueue, ElemType e) {
    if (isFull(pQueue)) {
        perror("can't enqueue to full queue");
        return false;
    }
    pQueue->base[pQueue->rear] = e;
    pQueue->rear++;
    return true;
}

ElemType dequeue(Queue *pQueue) {
    if (isEmpty(pQueue)) {
        perror("can't dequeue from empty queue.");
    }
    return pQueue->base[pQueue->front++];
}

ElemType getFront(Queue *pQueue) {
    if (isEmpty(pQueue)) {
        perror("can't get front from empty queue.");
    }
    return pQueue->base[pQueue->front];
}

ElemType getRear(Queue *pQueue) {
    if (isEmpty(pQueue)) {
        perror("can't get rear from empty queue.");
    }
    return pQueue->base[pQueue->rear - 1];
}

void printQueue(Queue *pQueue) {
    for (int i = pQueue->front; i < pQueue->rear; ++i) {
        printf("%d\t", pQueue->base[i]);
    }
    printf("\n");
}

void clear(Queue *pQueue) {
    pQueue->front = pQueue->rear = 0;
}

void test() {
    Queue queue;
    initQueue(&queue);
    assert(isEmpty(&queue));
    assert(size(&queue) == 0);

    for (int i = 1; i <= 4; ++i) {
        enqueue(&queue, i);
    }
    assert(!isFull(&queue));
    assert(size(&queue) == 4);
    printQueue(&queue); /* 1	2	3	4 */
    assert(1 == dequeue(&queue));
    assert(2 == getFront(&queue));
    assert(2 == dequeue(&queue));
    printQueue(&queue); /* 3	4 */
    enqueue(&queue, 5);
    assert(isFull(&queue));
    printQueue(&queue); /* 3	4	5 */
    assert(5 == getRear(&queue));
    assert(3 == size(&queue));
    clear(&queue);
    assert(isEmpty(&queue));
}

int main() {
    test();
    return 0;
}

