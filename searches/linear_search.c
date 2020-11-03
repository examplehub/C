#include <assert.h>

/**
 * Search a element at an array and return index of element.
 * @param arr the array contains elements.
 * @param len the number of elements of array.
 * @param key the key value to be searched.
 * @return index if found, otherwise -1 is returned.
 */
int search(const int *arr, int len, int key) {
    for (int i = 0; i < len; ++i) {
        if (arr[i] == key) {
            return i;
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
