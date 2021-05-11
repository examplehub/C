#include <assert.h>
#include <stdlib.h>

/**
 * Selection sort algorithm implements with recursion.
 * @param array the array to be sorted.
 * @param length the length of array.
 */
void selectionSort(int *array, int length) {
    if (length <= 1) {
        return;
    }
    int maxIndex = length - 1;
    for (int i = length - 2; i >= 0; --i) {
        if (array[i] > array[maxIndex]) {
            maxIndex = i;
        }
    }
    if (maxIndex != length - 1) {
        int temp = array[length - 1];
        array[length - 1] = array[maxIndex];
        array[maxIndex] = temp;
    }
    selectionSort(array, length - 1);
}

void test() {
    const int size = 10;
    int *arr = (int *) calloc(size, sizeof(int));

    /* generate size random numbers from 0 to 100 */
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    selectionSort(arr, size);
    for (int i = 0; i < size - 1; ++i) {
        assert(arr[i] <= arr[i + 1]);
    }
    free(arr);
}

int main() {
    test();
    return 0;
}
