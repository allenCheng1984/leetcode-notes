#include <stdio.h>
#include <stdbool.h>

/* 不用乘法和除法運算，只用 bitwise 的做法 */
bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x == 0) return true;

    int n = x;
    unsigned rev = 0;

    do {
        unsigned q = (x >> 1) + (x >> 2);
        q += q >> 4;
        q += q >> 8;
        q += q >> 16;
        q >>= 3;
        unsigned char rem = x - ((q << 1) + (q << 3));
        if (rem > 9)
            q++, rem -= 10;
        rev = ((rev << 1) + (rev << 3)) + rem;
        x = q;
    } while (x);

    return n == rev;
}
