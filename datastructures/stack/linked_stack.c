#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

typedef struct LinkedStack {
    Node *top; /* the top of this stack */
    int size; /* the number of elements in stack */
} LinkedStack;

/**
 * Initialized stack.
 * @param pStack
 */
void initStack(LinkedStack *pStack) {
    pStack->top = NULL;
    pStack->size = 0;
}

/**
 * Test if the pStack is empty or not.
 * @param pStack the pStack to be test.
 * @return true if pStack is empty, otherwise false.
 */
bool isEmpty(LinkedStack *pStack) {
    return pStack->size == 0;
}

/**
 * Return the number of elements at the stack.
 * @param stack the stack contains elements.
 * @return the number of elements at the stack.
 */
int size(LinkedStack *pStack) {
    return pStack->size;
}

/**
 * Add element to top of stack.
 * @param pStack the pointer of stack.
 * @param elem the element to be added.
 * @return true if added successfully.
 */
bool push(LinkedStack *pStack, ElemType elem) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("stackoverflow");
    }
    newNode->data = elem;
    newNode->next = pStack->top;
    pStack->top = newNode;
    pStack->size++;
    return true;
}

/**
 * Remove element at top of the stack.
 * @param pStack the pointer of stack.
 * @return element at the top of stack.
 */
ElemType pop(LinkedStack *pStack) {
    if (pStack->size == 0) {
        perror("Can't pop from empty stack");
    }
    Node *poppedNode = pStack->top;
    ElemType poppedElem = poppedNode->data;
    pStack->top = pStack->top->next;
    free(poppedNode);
    pStack->size--;
    return poppedElem;
}

/**
 * Return the element at the top of stack.
 * @param stack the stack.
 * @return top element of stack.
 */
ElemType peek(LinkedStack *pStack) {
    if (isEmpty(pStack)) {
        perror("Can't peek from empty stack");
    }
    return pStack->top->data;
}

/**
 * Print stack elements.
 * @param stack the stack to be printed.
 */
void printStack(LinkedStack *pStack) {
    Node *temp = pStack->top;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void test() {
    LinkedStack stack;
    initStack(&stack);
    assert(isEmpty(&stack));
    assert(size(&stack) == 0);

    for (int i = 1; i <= 5; ++i) {
        push(&stack, i);
        assert(size(&stack) == i);
    }
    printStack(&stack); /* output: 5	4	3	2	1 */
    assert(size(&stack) == 5);
    assert(peek(&stack) == 5);

    for (int i = 5; i >= 1; --i) {
        assert(size(&stack) == i);
        assert(peek(&stack) == i);
        assert(pop(&stack) == i);
    }

    assert(size(&stack) == 0);
    assert(isEmpty(&stack));
    printStack(&stack); /* output: */
}

int main() {
    test();
    return 0;
}