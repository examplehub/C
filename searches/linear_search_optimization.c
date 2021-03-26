#include <assert.h>

/**
 * Search a element at an array and return index of element.
 * @param arr the array contains elements.
 * @param len the number of elements of array.
 * @param key the key value to be searched.
 * @return index if found, otherwise -1 is returned.
 */
int search(int *arr, int len, int key) {
    if (key == arr[0]) {
        return 0;
    }
    int temp = arr[0];
    arr[0] = key;
    int index = len - 1;
    while (key != arr[index]) {
        index--;
    }
    arr[0] = temp;
    return index != 0 ? index : -1;
}

void test() {
    int arr[10];
    /* init array */
    for (int i = 0; i < 10; ++i) {
        arr[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        assert(search(arr, 10, arr[i]) == i);
    }
    assert(search(arr, 10, 66) == -1);
    assert(search(arr, 10, 66) == -1);

}

int main() {
    test();
    return 0;
}
