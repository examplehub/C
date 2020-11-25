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
    pQueue->base = malloc(sizeof(ElemType) * MAX_SIZE);
    pQueue->front = pQueue->rear = 0;
}

bool isEmpty(Queue queue) {
    return queue.front == queue.rear;
}

bool isFull(Queue queue) {
    return (queue.rear + 1) % MAX_SIZE == queue.front;
}

int length(Queue queue) {
    return (queue.rear - queue.front + MAX_SIZE) % MAX_SIZE;
}

bool enqueue(Queue *pQueue, ElemType elem) {
    if (isFull(*pQueue)) {
        perror("can't enqueue to full queue");
        return false;
    }
    pQueue->base[pQueue->rear] = elem;
    pQueue->rear = (pQueue->rear + 1) % MAX_SIZE;
    return true;
}

ElemType dequeue(Queue *pQueue) {
    if (isEmpty(*pQueue)) {
        perror("can't dequeue from empty queue.");
    }
    ElemType elem = pQueue->base[pQueue->front];
    pQueue->front = (pQueue->front + 1) % MAX_SIZE;
    return elem;
}

void printQueue(Queue queue) {
    for (int i = queue.front; i != queue.rear; i = (i + 1) % MAX_SIZE) {
        printf("%d\t", queue.base[i]);
    }
    printf("\n");
}

void clear(Queue *pQueue) {
    pQueue->rear = pQueue->front = 0;
}

void destroy(Queue *pQueue) {
    pQueue->rear = pQueue->front = 0;
    free(pQueue->base);
}

void test() {
    Queue queue;
    initQueue(&queue);
    assert(isEmpty(queue));
    assert(length(queue) == 0);

    for (int i = 1; i <= 4; ++i) {
        enqueue(&queue, i);
    }
    assert(isFull(queue));
    assert(length(queue) == 4);
    printQueue(queue); /* output: 1 2 3 4 */

    assert(dequeue(&queue) == 1);
    assert(dequeue(&queue) == 2);
    printQueue(queue); /* output: 3	4 */

    enqueue(&queue, 666);
    enqueue(&queue, 888);
    printQueue(queue); /* 3 4 666 888 */

    assert(dequeue(&queue) == 3);
    assert(dequeue(&queue) == 4);
    assert(dequeue(&queue) == 666);

    assert(length(queue) == 1);
    printQueue(queue); /* 888 */

    clear(&queue);
    assert(isEmpty(queue));
    assert(length(queue) == 0);

    destroy(&queue);
}

int main() {
    test();
    return 0;
}