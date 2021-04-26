#include <assert.h>

/**
 * Search a element at an array and return index of element using binary search recursion.
 * @param arr the array contains elements.
 * @param key the key value to be searched.
 * @param low the low index of subarray.
 * @param high the high index of subarray.
 * @return index if found, otherwise -1 is returned.
 */
int search(const int *arr, int key, int low, int high) {
    if (low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (key == arr[mid]) {
        return mid;
    } else if (key > arr[mid]) {
        return search(arr, key, mid + 1, high);
    } else {
        return search(arr, key, low, mid - 1);
    }
}

void test() {
    int arr[10];
    int size = 10;
    /* init array */
    for (int i = 0; i < size; ++i) {
        arr[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        assert(search(arr, arr[i], 0, size - 1) == i);
    }
    assert(search(arr, 66, 0, size - 1) == -1);
    assert(search(arr, 10, 0, size - 1) == -1);
}

int main() {
    test();
    return 0;
}