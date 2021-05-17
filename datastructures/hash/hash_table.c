#include <assert.h>
#define MAX 13


/**
 * Return hash address
 * @param key the key value to be calculate.
 * @return hash address of given key value.
 */
int hash(int key) {
    return key % MAX;
}

/**
 * Put key value to hash table.
 * @param hashTable the array store elements.
 * @param key the key to be put.
 */
void put(int hashTable[], int key) {
    int index = hash(key);
    while (hashTable[index] != 0) {
        index = (index + 1) % MAX;
    }
    hashTable[index] = key;
}

int search(const int hashTable[], int key) {
    int index = hash(key);
    while (hashTable[index] != 0) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (index + 1) % MAX;
    }
    return -1;
}

void test() {
    int arr[] = {25, 51, 8, 22, 26, 67, 11, 16, 54, 41};
    int hashTable[MAX] = {0};
    for (int i = 0, len = sizeof(arr) / sizeof(arr[0]); i < len; ++i) {
        put(hashTable, arr[i]);
    }
    int data[] = {51, 26, 67, 16, 54, 41, 0, 0, 8, 22, 0, 11, 25};
    for (int i = 0, len = sizeof(data) / sizeof(data[0]); i < len; ++i) {
        assert(data[i] == hashTable[i]);
    }

    for (int i = 0, len = sizeof(data) / sizeof(data[0]); i < len; ++i) {
        if (data[i] != 0) {
            assert(i == search(hashTable, data[i]));
        }
    }
}

int main() {
    test();
    return 0;
}

