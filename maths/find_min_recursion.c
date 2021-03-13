#include <assert.h>

/**
 * Find min value from given array.
 * @param arr the array contains elements.
 * @param length the length of array.
 * @return min value of array.
 */
int findMin(const int *arr, int length) {
    if (length == 1) {
        return arr[0];
    } else {
        int min = findMin(arr, length - 1);
        return min < arr[length - 1] ? min : arr[length - 1];
    }
}

void test() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(findMin(array, sizeof(array) / sizeof(array[0])) == 1);
}

int main() {
    test();
    return 0;
}
