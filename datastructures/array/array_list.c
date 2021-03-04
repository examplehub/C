#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define INIT_CAPACITY 100
#define INCREMENT 10
typedef int ElemType;
typedef struct ArrayList {
    ElemType *base;
    int size;
    int capacity;
} ArrayList;

/**
 * Init arraylist
 * @param plist
 */
void init(ArrayList *plist) {
    plist->base = malloc(sizeof(ElemType) * INIT_CAPACITY);
    plist->size = 0;
    plist->capacity = INIT_CAPACITY;
}

/**
 * Test if arraylist is empty or not.
 * @param list the list to be checked.
 * @return true if arraylist is empty, otherwise false.
 */
bool isEmpty(ArrayList list) {
    return list.size == 0;
}

/**
 * Allocate more memory.
 * @param plist the list to be allocated.
 */
void growCapacity(ArrayList *plist) {
    int newCapacity = (plist->capacity + INCREMENT);
    ElemType *newBase = realloc(plist->base,
                                sizeof(ElemType) * newCapacity);
    if (newBase != NULL) {
        plist->base = newBase;
        plist->capacity = newCapacity;
    } else {
        perror("stackoverflow");
    }
}

/**
 * Insert an element to list.
 * @param plist the list store elements.
 * @param index the index to inserted.
 * @param element the element to be inserted.
 * @return true if inserted successfully.
 */
bool insertNth(ArrayList *plist, int index, ElemType element) {
    if (index < 0 || index > plist->size) {
        perror("invalid insertion index");
        return false;
    }
    if (plist->size == plist->capacity) {
        growCapacity(plist);
    }
    for (int i = plist->size - 1; i >= index; --i) {
        *(plist->base + i + 1) = *(plist->base + i);
    }
    *(plist->base + index) = element;

    plist->size++;
    return true;
}

/**
 * Insert an element to the head of arraylist.
 * @param plist the list store elements.
 * @param element the element to be inserted.
 * @return true if insert successfully.
 */
bool insertHead(ArrayList *plist, ElemType element) {
    return insertNth(plist, 0, element);
}

/**
 * Insert an element to the tail of arraylist.
 * @param plist the list store elements.
 * @param element the element to be inserted.
 * @return true if insert successfully.
 */
bool insertTail(ArrayList *plist, ElemType element) {
    return insertNth(plist, plist->size, element);
}

/**
 * Delete an element at special index.
 * @param plist the list store elements.
 * @param index the index of element to be deleted.
 * @return element at special index.
 */
ElemType deleteNth(ArrayList *plist, int index) {
    if (index < 0 || index > plist->size - 1) {
        perror("invalid deletion index");
    }

    ElemType deletedElem = *(plist->base + index);
    for (int i = index; i < plist->size - 1; i++) {
        *(plist->base + i) = *(plist->base + i + 1);
    }
    plist->size--;
    return deletedElem;
}

/**
 * Delete an element at head of arraylist.
 * @param plist the list store elements.
 * @return element at head.
 */
ElemType deleteHead(ArrayList *plist) {
    return deleteNth(plist, 0);
}

/**
 * Delete an element at tail of arraylist.
 * @param plist the list store elements.
 * @return element at tail.
 */
ElemType deleteTail(ArrayList *plist) {
    return deleteNth(plist, plist->size - 1);
}

/**
 * Update an element at special index.
 * @param plist the list store elements.
 * @param index the index of element to be updated.
 * @param newValue the new value to set.
 * @return old value at special index.
 */
ElemType set(ArrayList *plist, int index, ElemType newValue) {
    if (index < 0 || index > plist->size - 1) {
        perror("invalid update index");
    }
    ElemType oldValue = *(plist->base + index);
    *(plist->base + index) = newValue;
    return oldValue;
}

/**
 * Get an element at special index of arraylist.
 * @param list the list store elements.
 * @param index the special index of arraylist.
 * @return the element at special index.
 */
ElemType get(ArrayList list, int index) {
    if (index < 0 || index > list.size - 1) {
        perror("invalid get index");
    }
    return *(list.base + index);
}

/**
 * Return the number of elements at arraylist.
 * @param list the list store elements.
 * @return the number of elements at arraylist.
 */
int size(ArrayList list) {
    return list.size;
}

/**
 * Travel elements of arraylist.
 * @param list the list store elements.
 */
void travel(ArrayList list) {
    for (int i = 0; i < list.size; i++) {
        printf("%d\t", *(list.base + i));
    }
    printf("\n");
}

/**
 * Clear all elements of arraylist.
 * @param plist the list store elements.
 */
void clear(ArrayList *plist) {
    plist->size = 0;
}

/**
 * Destroy the list.
 * @param plist the list to be destroyed.
 */
void destroy(ArrayList *plist) {
    plist->size = 0;
    free(plist->base);
}

/**
 * Merge two sorted list.
 * @param plistA the first sorted list.
 * @param plistB the second sorted list.
 * @param plistC the sorted list after merged.
 */
void merge(ArrayList *plistA, ArrayList *plistB, ArrayList *plistC) {
    int pa = 0;
    int pb = 0;
    int pc = 0;
    while (pa < plistA->size && pb < plistB->size) {
        if (plistA->base[pa] <= plistB->base[pb]) {
            plistC->base[pc++] = plistA->base[pa++];
        } else {
            plistC->base[pc++] = plistB->base[pb++];
        }
    }

    while (pa < plistA->size) {
        plistC->base[pc++] = plistA->base[pa++];
    }

    while (pb < plistB->size) {
        plistC->base[pc++] = plistB->base[pb++];
    }

    plistC->size = plistA->size + plistB->size;
}

void test() {
    ArrayList list;
    init(&list);
    assert(isEmpty(list));

    for (int i = 0; i < 5; ++i) {
        insertNth(&list, i, i + 1);
    }
    insertHead(&list, 0);
    insertTail(&list, 6);
    assert(size(list) == 7);

    for (int i = 0; i < 7; ++i) {
        assert(i == get(list, i));
    }

    travel(list); /* output: 0 1 2 3 4 5 6 */
    assert(deleteHead(&list) == 0);
    assert(deleteTail(&list) == 6);
    travel(list); /* output: 1 2 3 4 5 */
    assert(deleteNth(&list, 2) == 3);
    travel(list); /* output: 1 2 4 5 */

    clear(&list);
    destroy(&list);
}

void testMerge()
{
    ArrayList listA;
    ArrayList listB;
    init(&listA);
    init(&listB);
    for (int i = 1, j = 0; i <= 10; i += 2, j++) {
        insertNth(&listA, j, i);
        insertNth(&listB, j, i + 1);
    }
    travel(listA); /* output: 1	3	5	7	9 */
    travel(listB); /* output: 2	4	6	8	10 */

    ArrayList listC;
    init(&listC);
    merge(&listA, &listB, &listC);
    travel(listC); /* output: 1	   2	3	4	5	6	7	8	9	10 */
    for (int i = 0; i < listC.size - 1; ++i) {
        assert(get(listC, i) <= get(listC, i + 1));
    }
}

int main() {
    test();
    testMerge();
    return 0;
}
