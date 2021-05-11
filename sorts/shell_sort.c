#include <assert.h>
#include <time.h>
#include <stdlib.h>

void shellSort(int *array, int length) {
    for (int gap = length / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < length; ++i) {
            int key = array[i];
            int j;
            for (j = i - gap; j >= 0 && key < array[j]; j -= gap) {
                array[j + gap] = array[j];
            }
            if (j != i - gap) {
                array[j + gap] = key;
            }
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
    shellSort(arr, size);
    for (int i = 0; i < size - 1; ++i) {
        assert(arr[i] <= arr[i + 1]);
    }
    free(arr);
}

int main() {
    test();
    return 0;
}
