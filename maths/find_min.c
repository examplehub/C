#include <assert.h>
int findMin(const int *arr, int length){
    int min = arr[0];
    for (int i = 1; i < length; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void test(){
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(findMin(array, sizeof(array) / sizeof(array[0])) == 1);
}

int main(){
    test();
    return 0;
}
