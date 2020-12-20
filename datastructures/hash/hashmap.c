#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE 20

typedef struct Item {
    int key;
    int value;
} Item;

typedef struct HashMap {
    Item *array[MAX_SIZE];
    int size;
} HashMap;

int hashCode(int key) {
    return key % MAX_SIZE;
}

void init(HashMap *hashMap) {
    for (int i = 0; i < MAX_SIZE; ++i) {
        hashMap->array[i] = NULL;
    }
    hashMap->size = 0;
}

void put(HashMap *hashMap, int key, int value) {
    int hash = hashCode(key);
    while (hashMap->array[hash] != NULL) {
        hash = (hash + 1) % MAX_SIZE;
    }
    Item *newItem = malloc(sizeof(Item));
    newItem->key = key;
    newItem->value = value;
    hashMap->array[hash] = newItem;
}

int get(HashMap *hashMap, int key) {
    int hash = hashCode(key);
    while (hashMap->array[hash] != NULL) {
        if (hashMap->array[hash]->key == key) {
            return hashMap->array[hash]->value;
        }
        hash = (hash + 1) % MAX_SIZE;
    }
    return -1;
}

void printHashMap(HashMap *hashMap) {
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (hashMap->array[i] != NULL) {
            printf("key = %d, value = %d\n",
                   hashMap->array[i]->key, hashMap->array[i]->value);
        }
    }
    printf("\n");
}

void test() {
    int data[][2] = {
            {1,  20},
            {2,  70},
            {42, 80},
            {4,  25},
            {12, 44},
            {14, 32},
            {17, 11},
            {13, 78},
            {37, 97}
    };
    int len = sizeof(data) / sizeof(data[0]);
    assert(len == 9);

    HashMap hashMap;
    init(&hashMap);
    for (int i = 0; i < len; ++i) {
        put(&hashMap, data[i][0], data[i][1]);
    }
    for (int i = 0; i < len; i++) {
        assert(get(&hashMap, data[i][0]) == data[i][1]);
    }
}

int main() {
    test();
    return 0;
}