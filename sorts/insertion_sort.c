#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void insertionSort(int *array, int length) {
    for (int i = 1; i < length; i++) {
        int key = array[i];
        int j;
        for (j = i - 1; j >= 0 && key < arr[j]; j--) {
            arr[j + 1] = arr[j];
        }
        if (j != i - 1) {
            array[j + 1] = key;
        }
    }
}

void test() {
    /* initial random number generator */
    srand(time(NULL));
    const int size = 10;
    int *arr = (int *) calloc(size, sizeof(int));

    /* generate size random numbers from 0 to 100 */
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    insertionSort(arr, size);
    for (int i = 0; i < size - 1; ++i) {
        assert(arr[i] <= arr[i + 1]);
    }
    free(arr);
}

int main() {
    test();
    return 0;
}
