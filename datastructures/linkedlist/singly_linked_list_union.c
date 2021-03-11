#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElemType;
typedef struct Node {
    union {
        ElemType data;
        int length;
    };
    struct Node *next;
} Node;

/**
 * Create header of SinglyLinkedList.
 * @return header pointer of SinglyLinkedList.
 */
Node *init() {
    Node *header = malloc(sizeof(Node));
    if (header != NULL) {
        header->next = NULL;
        header->length = 0;
    }
    return header;
}

void insertOrder(Node *root, ElemType elem) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = elem;
    Node *temp = root;
    while (temp != NULL && temp->next != NULL && elem > temp->next->data) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    root->length++;
}

void insertNth(Node *root, int index, ElemType elem) {
    if (index < 0 || index > root->length) {
        perror("invalid insertion index");
    }
    Node *temp = root;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }

    Node *newNode = malloc(sizeof(Node));
    newNode->data = elem;
    newNode->next = temp->next;
    temp->next = newNode;
    root->length++;
}

ElemType deleteNth(Node *root, int index) {
    if (index < 0 || index > root->length - 1) {
        perror("invalid delete index");
    }
    Node *temp = root;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }
    Node *destroy = temp->next;
    ElemType data = destroy->data;
    temp->next = temp->next->next;
    free(destroy);
    root->length--;
    return data;
}

void printSinglyLinkedList(Node *root) {
    Node *temp = root->next;
    for (int i = 1; i <= root->length; ++i) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void test() {
    Node *root = init();
    for (int i = 1; i <= 5; i += 2) {
        insertOrder(root, i);
    }
    for (int i = 0; i <= 4; i += 2) {
        insertOrder(root, i);
    }
    Node *temp = root->next;
    for (int i = 1; i <= root->length - 1; ++i) {
        assert(temp->data <= temp->next->data);
    }
    printSinglyLinkedList(root); /* output: 0	1	2	3	4	5 */

    root = init(); /* init new linked list */
    for (int i = 0; i <= 3; ++i) {
        insertNth(root, i, i + 1);
    }
    insertNth(root, 0, 0);
    insertNth(root, 5, 666);
    printSinglyLinkedList(root); /* output: 0	1	2	3	4	666 */

    assert(deleteNth(root, 0) == 0);
    assert(deleteNth(root, 4) == 666);
    printSinglyLinkedList(root);
    assert(deleteNth(root, 2) == 3);
    printSinglyLinkedList(root); /* output: 1	2	4 */
}

int main() {
    test();
    return 0;
}