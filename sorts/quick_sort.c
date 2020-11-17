#include <assert.h>
#include <stdlib.h>
#include <time.h>

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    while (low < high) {
        while (low < high && arr[low] <= pivot) {
            low++;
        }
        arr[high] = arr[low];
        while (low < high && arr[high] >= pivot) {
            high--;
        }
        arr[low] = arr[high];
    }
    arr[low] = pivot;
    return low;
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void test() {
    const int size = 10;
    int *arr = (int *) calloc(size, sizeof(int));

    /* generate size random numbers from 0 to 100 */
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    quickSort(arr, 0, size - 1);
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
