#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/**
 * Bubble Sort algorithm.
 * @param arr the array.
 * @param length the length of array.
 */
void bubbleSort(int *arr, int length) {
    for (int i = 0; i < length - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < length - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void test() {
    const int size = 10;
    int *arr = (int *) calloc(size, sizeof(int));

    /* generate size random numbers from 0 to 100 */
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    bubbleSort(arr, size);
    for (int i = 0; i < size - 1; ++i) {
        assert(arr[i] <= arr[i + 1]);
    }
    free(arr);
}

int main() {
    /* initial random number generator */
    srand(time(NULL));
    test();
    return 0;
}