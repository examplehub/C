#include <assert.h>

/**
 * Find max value from given array.
 * @param arr the array contains elements.
 * @param length the length of array.
 * @return max value of array.
 */
int findMax(const int *arr, int length){
    if (length == 1) {
        return arr[0];
    } else {
        int max = findMax(arr, length - 1);
        return max > arr[length - 1] ? max : arr[length - 1];
    }
}

void test(){
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(findMax(array, sizeof(array) / sizeof(array[0])) == 10);
}

int main(){
    test();
    return 0;
}
