#include <assert.h>
int findMax(const int *arr, int length){
    int max = arr[0];
    for (int i = 1; i < length; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void test(){
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(findMax(array, sizeof(array) / sizeof(array[0])) == 10);
}

int main(){
    test();
    return 0;
}
