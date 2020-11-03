#include <assert.h>
#include <string.h>

/**
 *
 * @param original the origin text.
 * @param steps the steps to be moved.
 * @return the string encrypted.
 */
char *encrypt(char *original, int steps) {
    for (int i = 0; original[i] != '\0'; ++i) {
        if (original[i] >= 'A' && original[i] <= 'Z') {
            original[i] = (char) ('A' + (original[i] - 'A' + steps) % 26);
        } else if (original[i] >= 'a' && original[i] <= 'z') {
            original[i] = (char) ('a' + (original[i] - 'a' + steps) % 26);
        }
    }
    return original;
}

/**
 * Decrypt a string.
 * @param password the password to be decrypted.
 * @param steps the steps to be moved.
 * @return the string decrypted.
 */
char *decrypt(char *password, int steps) {
    for (int i = 0; password[i] != '\0'; ++i) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            password[i] = (char) ('A' + (password[i] - 'A' - steps + 26) % 26);
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            password[i] = (char) ('a' + (password[i] - 'a' - steps + 26) % 26);
        }
    }
    return password;
}

void test() {
    char original[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    assert(strcmp("DEFGHIJKLMNOPQRSTUVWXYZABC", encrypt(original, 3)) == 0);

    strcpy(original, "abcdefghijklmnopqrstuvwxyz");
    assert(strcmp("defghijklmnopqrstuvwxyzabc", encrypt(original, 3)) == 0);

    char password[100] = "DEFGHIJKLMNOPQRSTUVWXYZABC";
    assert(strcmp("ABCDEFGHIJKLMNOPQRSTUVWXYZ", decrypt(password, 3)) == 0);

    strcpy(password, "defghijklmnopqrstuvwxyzabc");
    assert(strcmp("abcdefghijklmnopqrstuvwxyz", decrypt(password, 3)) == 0);
}

int main() {
    test();
    return 0;
}