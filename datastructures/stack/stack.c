#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10
typedef int ElemType;
typedef struct Stack {
    ElemType *base;
    int top;
} Stack;

/**
 * Init stack.
 * @param pStack
 */
void initStack(Stack *pStack) {
    pStack->base = malloc(MAX_SIZE * sizeof(ElemType));
    pStack->top = -1;
}

/**
 * Test if the stack is empty or not.
 * @param pStack the stack to be checked.
 * @return true if the stack is empty, otherwise fasle.
 */
bool isEmpty(Stack *pStack) {
    return pStack->top == -1;
}

/**
 * Test if the stack is full.
 * @param pStack the stack to be checked.
 * @return true if the stack contains no elements.
 */
bool isFull(Stack *pStack){
    return pStack->top + 1 == MAX_SIZE;
}

/**
 * Returns the count of numbers of stack.
 * @param pStack the stack to be calculated.
 * @return size of number of stack.
 */
int length(Stack *pStack) {
    return pStack->top + 1;
}

/**
 * Clear all elements of stack.
 * @param pStack the stack to be cleared.
 */
void clear(Stack *pStack) {
    pStack->top = -1;
}

/**
 * Destroy the stack memory allocated.
 * @param pStack the stack will be destroy.
 */
void destroy(Stack *pStack) {
    free(pStack->base);
    pStack->top = -1;
}

/**
 * Remove element from the top of stack.
 * @param pStack the stack contains elements.
 * @return the element at the top of stack.
 */
ElemType pop(Stack *pStack){
    if (isEmpty(pStack)){
        perror("pop from empty stack.");
    }
    return pStack->base[pStack->top--];
}

/**
 * Add element to the top of stack.
 * @param pStack the stack contains elements.
 * @param elem the element to added.
 * @return true if pushed, otherwise false.
 */
bool push(Stack *pStack, ElemType elem){
    if (isFull(pStack)){
        perror("can't push full stack.");
        return false;
    }
    pStack->base[++pStack->top] = elem;
    return true;
}

/**
 * Get the element at the top of stack.
 * @param pStack the stack.
 * @return the stack contains elements
 */
ElemType peek(Stack *pStack) {
    if (isEmpty(pStack)) {
        perror("can't peek from empty stack.");
    }
    return pStack->base[pStack->top];
}

void test() {
    Stack stack;
    initStack(&stack);
    assert(isEmpty(&stack));
    assert(length(&stack) == 0);

    for (int i = 1; i <= 5; ++i) {
        push(&stack, i);
    }
    assert(peek(&stack) == 5);
    assert(length(&stack) == 5);
    for (int i = 5; i >= 1; --i) {
        assert(pop(&stack) == i);
    }

    clear(&stack);
    assert(isEmpty(&stack));

    destroy(&stack);
}

int main() {
    test();
    return 0;
}