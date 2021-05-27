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

/**
 * Create header of SinglyLinkedList.
 * @return header pointer of SinglyLinkedList.
 */
Node *init() {
    Node *head = malloc(sizeof(Node));
    if (head != NULL) {
        head->next = NULL;
        head->length = 0;
    }
    return head;
}

/**
 * Insert element to sorted singly linked list always is sorted.
 * @param head the head pointer
 * @param elem the element to be inserted.
 */
void insertOrder(Node *head, ElemType elem) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = elem;
    Node *temp = head;
    while (temp != NULL && temp->next != NULL && elem > temp->next->data) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    head->length++;
}

/**
 * Insert a element to given position of singly linked list.
 * @param head the head pointer of singly linked list.
 * @param pos the position inserted.
 * @param elem the element inserted.
 */
void insertNth(Node *head, int pos, ElemType elem) {
    if (pos < 1 || pos > head->length + 1) {
        perror("invalid insertion position");
    }
    Node *temp = head;
    for (int i = 1; i < pos; ++i) {
        temp = temp->next;
    }

    Node *newNode = malloc(sizeof(Node));
    newNode->data = elem;
    newNode->next = temp->next;
    temp->next = newNode;
    head->length++;
}

/**
 * Delete a element at the given position.
 * @param head the pointer of singly linked list.
 * @param pos the position of element to be deleted.
 * @return deleted element.
 */
ElemType deleteNth(Node *head, int pos) {
    if (pos < 1 || pos > head->length) {
        perror("invalid delete position");
    }
    Node *temp = head;
    for (int i = 1; i < pos; ++i) {
        temp = temp->next;
    }
    Node *destroy = temp->next;
    ElemType data = destroy->data;
    temp->next = temp->next->next;
    free(destroy);
    head->length--;
    return data;
}

/**
 * Print all elements at singly linked list.
 * @param head
 */
void printSinglyLinkedList(Node *head) {
    Node *temp = head->next;
    for (int i = 1; i <= head->length; ++i) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * Returns the count number of singly linked list.
 * @param head the head pointer of singly linked list.
 * @return the count number of singly linked list.
 */
int size(Node *head) {
    return head->length;
}

/**
 * Test if the singly linked list is empty.
 * @param head the head pointer of singly linked list.
 * @return true if singly linked list contains no elements, otherwise true.
 */
bool isEmpty(Node *head) {
    return head->length == 0;
}

/**
 * Clear all elements of singly linked list.
 * @param head the head pointer of singly linked list.
 */
void clear(Node *head) {
    Node *cur = head->next;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    head->next = NULL;
    head->length = 0;
}

/**
 * Destroy singly linked list.
 * @param head
 */
void destroy(Node *head) {
    while (head != NULL) {
        Node *cur = head->next;
        free(head);
        head = cur;
    }
}

void test() {
    Node *head = init();
    for (int i = 1; i <= 5; i += 2) {
        insertOrder(head, i);
    }
    for (int i = 0; i <= 4; i += 2) {
        insertOrder(head, i);
    }
    assert(size(head) == 6);
    Node *temp = head->next;
    for (int i = 1; i <= head->length - 1; ++i) {
        assert(temp->data <= temp->next->data);
    }
    printSinglyLinkedList(head); /* output: 0	1	2	3	4	5 */

    head = init(); /* init new linked list */
    for (int i = 1; i <= 3; ++i) {
        insertNth(head, i, i);
    }
    insertNth(head, 1, 111);
    insertNth(head, 5, 666);

    assert(deleteNth(head, 1) == 111);
    assert(deleteNth(head, 4) == 666);
    assert(deleteNth(head, 2) == 2);
    printSinglyLinkedList(head); /* output: 1   3 */

    clear(head);
    assert(isEmpty(head));
    destroy(head);
}

int main() {
    test();
    return 0;
}