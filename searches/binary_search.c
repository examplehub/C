#include <assert.h>

/**
 * Search a element at an array and return index of element using binary search.
 * @param arr the array contains elements.
 * @param len the number of elements of array.
 * @param key the key value to be searched.
 * @return index if found, otherwise -1 is returned.
 */
int search(const int *arr, int len, int key) {
    int low = 0;
    int high = len - 1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (key == arr[mid]) {
            return mid;
        } else if (key > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void test(){
    int arr[10];
    /* init array */
    for (int i = 0; i < 10; ++i) {
        arr[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        assert(search(arr, 10, arr[i]) == i);
    }
    assert(search(arr, 10, 66) == -1);
    assert(search(arr, 10, 10) == -1);

}
int main(){
    test();
    return 0;
}