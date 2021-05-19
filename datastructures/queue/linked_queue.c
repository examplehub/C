#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

typedef struct {
    Node *front; /* front pointer of LinkedQueue */
    Node *rear; /* rear pointer of LinkedQueue */
    int size; /* the number count of LinkedQueue */
} LinkedQueue;

void initQueue(LinkedQueue *queue) {
    queue->front = queue->rear = NULL;
    queue->size = 0;
}

/**
 * Test if queue is empty.
 * @param queue the queue to be checked.
 * @return true if queue is empty, otherwise false.
 */
bool isEmpty(LinkedQueue *queue) {
    return queue->size == 0;
}

/**
 * Return the size of queue.
 * @param queue the queue to be calculated.
 * @return size of queue.
 */
int size(LinkedQueue *queue) {
    return queue->size;
}

/**
 * EnQueue a data to queue.
 * @param queue the queue contains elements.
 * @param data the data to be added.
 * @return true if add successfully.
 */
bool enQueue(LinkedQueue *queue, ElemType data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear = queue->rear->next = newNode;
    }
    queue->size++;
    return true;
}

/**
 * Remove element at the front of queue.
 * @param queue the queue contains elements.
 * @return the element at the front of queue.
 */
ElemType deQueue(LinkedQueue *queue) {
    if (isEmpty(queue)) {
        perror("can't dequeue from empty queue.");
    }
    ElemType retValue = queue->front->data;
    if ((queue->front = queue->front->next) == NULL) {
        queue->rear = NULL;
    }
    queue->size--;
    return retValue;
}

void clearQueue(LinkedQueue *queue) {
    if (!isEmpty(queue)) {
        struct Node *cur = queue->front;
        struct Node *next = cur->next;
        while (next != NULL) {
            free(cur);
            cur = next;
            next = next->next;
        }
        free(cur);
        queue->front = queue->rear = NULL;
        queue->size = 0;
    }
}

void printQueue(LinkedQueue *queue) {
    struct Node *temp = queue->front;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void test() {
    LinkedQueue queue;
    initQueue(&queue);
    assert(isEmpty(&queue));
    assert(size(&queue) == 0);

    for (int i = 1; i <= 4; ++i) {
        enQueue(&queue, i);
    }
    assert(size(&queue) == 4);
    printQueue(&queue); /* 1	2	3	4 */

    assert(deQueue(&queue) == 1);
    assert(deQueue(&queue) == 2);
    printQueue(&queue); /* 3	4 */

    enQueue(&queue, 666);
    enQueue(&queue, 888);
    printQueue(&queue); /* 3 4 666 888 */

    assert(deQueue(&queue) == 3);
    assert(deQueue(&queue) == 4);
    assert(deQueue(&queue) == 666);

    assert(size(&queue) == 1);
    printQueue(&queue); /* 888 */

    clearQueue(&queue);
    assert(isEmpty(&queue));
    assert(size(&queue) == 0);
}

int main(void) {
    test();
    return 0;
}

