#include <assert.h>
#include <stdlib.h>
#include <time.h>

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= pivot) {
            high--;
        }
        while (low < high && arr[low] <= pivot) {
            low++;
        }
        if (low < high) {
            swap(arr, low, high);
            low++;
            high--;
        }
    }
    arr[low] = pivot;
    assert(low >= high);
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

    int numbers[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    int len = sizeof(numbers) / sizeof(numbers[0]);
    quickSort(numbers, 0, len - 1);
    for (int i = 0; i < len - 1; ++i) {
        assert(numbers[i] <= numbers[i + 1]);
    }
}

int main() {
    /* initial random number generator */
    srand(time(NULL));
    test();
    return 0;
}
