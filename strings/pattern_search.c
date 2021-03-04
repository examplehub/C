#include <string.h>
#include <assert.h>

int search(char *pattern, char *txt) {
    int txt_len = strlen(txt);
    int pattern_len = strlen(pattern);
    int i = 0; /* index of txt */
    int j = 0; /* index of pattern */
    while (i < txt_len && j < pattern_len) {
        if (txt[i] == pattern[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    return j == pattern_len ? i - j : -1;
}

void test() {
    assert(search("ABC", "ABCABCDABCDE") == 0);
    assert(search("ABCD", "ABCABCDABCDE") == 3);
    assert(search("ABCDE", "ABCABCDABCDE") == 7);
    assert(search("AAA", "ABCABCDABCDE") == -1);
}

int main() {
    test();
    return 0;
}

