#include <assert.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int right) {
    int mid = left + (right - left) / 2; /* calculate middle index */
    int temp[right - left + 1];
    int p1 = left; /* begin index of first sub array */
    int p2 = mid + 1; /* begin index of second sub array */
    int p3 = 0; /* index of temp array */
    while (p1 <= mid && p2 <= right) {
        if (arr[p1] <= arr[p2]) {
            temp[p3++] = arr[p1++];
        } else {
            temp[p3++] = arr[p2++];
        }
    }

    /* copy left elements of first sub array to temp array */
    while (p1 <= mid) {
        temp[p3++] = arr[p1++];
    }

    /* copy left elements of second sub array to temp array */
    while (p2 <= right) {
        temp[p3++] = arr[p2++];
    }

    /* copy temp array elements back to original array */
    for (int i = 0; i <= p3; i++) {
        arr[left++] = temp[i];
    }
}

/**
 * Merge sort algorithm implement.
 * @param arr the array to be sorted.
 * @param left the left index of sub array.
 * @param right the right index of sub array.
 */
void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; /* calculate mid index */
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, right);
    }
}

void test() {
    const int size = 10;
    int *arr = (int *) calloc(size, sizeof(int));

    /* generate size random numbers from 0 to 100 */
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    mergeSort(arr, 0, size - 1);
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