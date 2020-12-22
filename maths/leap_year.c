#include <stdbool.h>
#include <assert.h>

/**
 * Test if a year is leap year or not.
 * @param year the year to be tested.
 * @return true if given year is leap year, otherwise false.
 */
bool isLeapYear(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

void test() {
    assert(isLeapYear(1600));
    assert(isLeapYear(2000));
    assert(!isLeapYear(1700));
    assert(!isLeapYear(1800));
    assert(!isLeapYear(1900));
}

int main() {
    test();
    return 0;
}
