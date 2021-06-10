#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

typedef struct SinglyLinkedList {
    Node *head; /* the head pointer of SinglyLinkedList */
    Node *tail; /* the tail pointer of SinglyLinkedList */
    int length; /* the number of elements of SinglyLinkedList */
} SinglyLinkedList;

/**
 * Initialize SinglyLinkedList.
 * @param list the list to be initialized.
 */
void init(SinglyLinkedList *list) {
    list->length = 0;
    list->head = list->tail = malloc(sizeof(Node));
}

/**
 * Test if SinglyLinkedList is empty or not.
 * @param list the list to be tested.
 * @return true if SinglyLinkedList is empty, otherwise false.
 */
bool isEmpty(SinglyLinkedList list) {
    return list.length == 0;
}

/**
 * Return the length of SinglyLinkedList.
 * @param list the list to be calculated.
 * @return the length of SinglyLinkedList.
 */
int length(SinglyLinkedList list) {
    return list.length;
}

/**
 * Insert element to the special position of SinglyLinkedList.
 * @param pList the list contains elements.
 * @param index the index to be inserted.
 * @param elem the element to be inserted.
 * @return true if inserted successfully, otherwise false.
 */
bool insertAt(SinglyLinkedList *pList, int index, ElemType elem) {
    if (index < 0 || index > pList->length) {
        perror("invalid insertion index.");
        return false;
    }
    Node *newNode = malloc(sizeof(Node));
    newNode->data = elem;

    if (index == pList->length) {
        pList->tail = pList->tail->next = newNode;
        pList->length++;
        return true;
    }
    Node *cur = pList->head;
    for (int i = 0; i < index; ++i) {
        cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    pList->length++;
    return true;
}

bool insertHead(SinglyLinkedList *pList, ElemType elem) {
    return insertAt(pList, 0, elem);
}

bool insertTail(SinglyLinkedList *pList, ElemType elem) {
    return insertAt(pList, pList->length, elem);
}

ElemType deleteAt(SinglyLinkedList *pList, int index) {
    if (index < 0 || index > pList->length - 1) {
        perror("invalid delete index.");
    }
    Node *deleteNode;
    Node *cur = pList->head;
    for (int i = 0; i < index; ++i) {
        cur = cur->next;
    }
    deleteNode = cur->next;
    ElemType retData = deleteNode->data;
    cur->next = cur->next->next;
    free(deleteNode);
    if (index == pList->length - 1) {
        pList->tail = cur;
    }
    pList->length--;
    return retData;
}

ElemType deleteHead(SinglyLinkedList *pList) {
    return deleteAt(pList, 0);
}

ElemType deleteTail(SinglyLinkedList *pList) {
    return deleteAt(pList, pList->length - 1);
}

/**
 * Reverse given SinglyLinkedList
 * @param plist the pointer of list to be reversed.
 */
void reverse(SinglyLinkedList *plist) {
    Node *prev = NULL;
    Node *current = plist->head->next;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    plist->head->next = prev;
}

void printLinkedList(SinglyLinkedList list) {
    Node *temp = list.head->next;
    for (int i = 0; i < list.length; ++i) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void test() {
    SinglyLinkedList list;
    init(&list);
    assert(length(list) == 0);
    assert(isEmpty(list));

    for (int i = 0; i <= 3; ++i) {
        insertAt(&list, i, i + 1);
    }
    printLinkedList(list); /* 1 2 3 4 */
    insertTail(&list, 5);
    insertHead(&list, 0);
    printLinkedList(list); /* 0 1 2 3 4 5 */

    assert(deleteAt(&list, 3) == 3);
    assert(deleteHead(&list) == 0);
    assert(deleteTail(&list) == 5);
    printLinkedList(list); /* 1 2 4 */

    reverse(&list);
    printLinkedList(list); /* 4 2 1 */

}

int main() {
    test();
    return 0;
}

