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

/**
 * Init queue.
 * @param pQueue the queue pointer.
 */
void initQueue(Queue *pQueue) {
    pQueue->base = malloc(sizeof(ElemType) * MAX_SIZE);
    pQueue->front = pQueue->rear = 0;
}

/**
 * Test if the queue is empty.
 * @param queue
 * @return true if the queue is empty, otherwise false.
 */
bool isEmpty(Queue *pQueue) {
    return pQueue->front == pQueue->rear;
}

/**
 * Test if the queue is full.
 * @param pQueue the queue pointer.
 * @return true if the queue is full, otherwise false.
 */
bool isFull(Queue *pQueue) {
    return (pQueue->rear + 1) % MAX_SIZE == pQueue->front;
}

/**
 * Returns the count number of the queue.
 * @param pQueue the queue pointer.
 * @return length of queue.
 */
int length(Queue *pQueue) {
    return (pQueue->rear - pQueue->front + MAX_SIZE) % MAX_SIZE;
}

/**
 *
 * @param pQueue the queue pointer of queue.
 * @param elem the element will add to queue.
 * @return true if add successfully, otherwise false.
 */
bool enqueue(Queue *pQueue, ElemType elem) {
    if (isFull(pQueue)) {
        perror("can't enqueue to full queue");
        return false;
    }
    pQueue->base[pQueue->rear] = elem;
    pQueue->rear = (pQueue->rear + 1) % MAX_SIZE;
    return true;
}

/**
 * Remove element from queue.
 * @param pQueue the pointer of queue.
 * @return the element at front of queue.
 */
ElemType dequeue(Queue *pQueue) {
    if (isEmpty(pQueue)) {
        perror("can't dequeue from empty queue.");
    }
    ElemType elem = pQueue->base[pQueue->front];
    pQueue->front = (pQueue->front + 1) % MAX_SIZE;
    return elem;
}

/**
 * Print all elements of queue.
 * @param pQueue the queue pointer.
 */
void printQueue(Queue *pQueue) {
    for (int i = pQueue->front; i != pQueue->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d\t", pQueue->base[i]);
    }
    printf("\n");
}

/**
 * Remove all elements of queue without free memory.
 * @param pQueue the pointer of queue.
 */
void clear(Queue *pQueue) {
    pQueue->rear = pQueue->front = 0;
}

/**
 * Remove all elements of queue and free memory.
 * @param pQueue the pointer of queue.
 */
void destroy(Queue *pQueue) {
    pQueue->rear = pQueue->front = 0;
    free(pQueue->base);
}

void test() {
    Queue queue;
    initQueue(&queue);
    assert(isEmpty(&queue));
    assert(length(&queue) == 0);

    for (int i = 1; i <= 4; ++i) {
        enqueue(&queue, i);
    }
    assert(isFull(&queue));
    assert(length(&queue) == 4);
    printQueue(&queue); /* output: 1 2 3 4 */

    assert(dequeue(&queue) == 1);
    assert(dequeue(&queue) == 2);
    printQueue(&queue); /* output: 3	4 */

    enqueue(&queue, 666);
    enqueue(&queue, 888);
    printQueue(&queue); /* 3 4 666 888 */

    assert(dequeue(&queue) == 3);
    assert(dequeue(&queue) == 4);
    assert(dequeue(&queue) == 666);

    assert(length(&queue) == 1);
    printQueue(&queue); /* 888 */

    clear(&queue);
    assert(isEmpty(&queue));
    assert(length(&queue) == 0);

    destroy(&queue);
}

int main() {
    test();
    return 0;
}