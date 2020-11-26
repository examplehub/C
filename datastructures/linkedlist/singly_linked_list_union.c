#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct Node {
    union {
        ElemType data;
        int length;
    };
    struct Node *next;
} Node;

Node *init() {
    Node *root = malloc(sizeof(Node));
    root->next = NULL;
    root->length = 0;
    return root;
}

void insertOrder(Node *root, ElemType elem) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = elem;
    newNode->next = NULL;
    Node *temp = root;
    while (temp != NULL && temp->next != NULL && elem > temp->next->data) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    root->length++;
}

void printSinglyLinkedList(Node *root) {
    Node *temp = root->next;
    for (int i = 0; i < root->length; ++i) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void test() {
    Node *root = init();
    for (int i = 1; i <= 5; i += 2) {
        insertOrder(root, i);
    }
    for (int i = 0; i <= 4; i += 2) {
        insertOrder(root, i);
    }
    printSinglyLinkedList(root);
}

int main() {
    test();
    return 0;
}