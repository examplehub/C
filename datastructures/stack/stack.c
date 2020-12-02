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

void initStack(Stack *pStack);

bool isEmpty();

void initStack(Stack *pStack) {
    pStack->base = malloc(MAX_SIZE * sizeof(ElemType));
    pStack->top = -1;
}

bool isEmpty(Stack stack) {
    return stack.top == -1;
}

bool isFull(Stack stack){
    return stack.top == MAX_SIZE - 1;
}

int length(Stack stack) {
    return stack.top + 1;
}

void clear(Stack *pStack) {
    pStack->top = -1;
}

void destroy(Stack *pStack) {
    free(pStack->base);
    pStack->top = -1;
}

ElemType pop(Stack *pStack){
    if (isEmpty(*pStack)){
        perror("pop from empty stack.");
    }
    return pStack->base[pStack->top--];
}

bool push(Stack *pStack, ElemType elem){
    if (isFull(*pStack)){
        perror("can't push full stack.");
        return false;
    }
    pStack->base[++pStack->top] = elem;
    return true;
}

ElemType peek(Stack stack) {
    if (isEmpty(stack)) {
        perror("can't peek from empty stack.");
    }
    return stack.base[stack.top];
}

void test() {
    Stack stack;
    initStack(&stack);
    assert(isEmpty(stack));
    assert(length(stack) == 0);

    for (int i = 1; i <= 5; ++i) {
        push(&stack, i);
    }
    assert(peek(stack) == 5);
    assert(length(stack) == 5);
    for (int i = 5; i >= 1; --i) {
        assert(pop(&stack) == i);
    }

    clear(&stack);
    assert(isEmpty(stack));

    destroy(&stack);
}

int main() {
    test();
    return 0;
}