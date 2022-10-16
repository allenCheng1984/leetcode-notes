#include <stdio.h>
#include <stdbool.h>

/* 不將數字轉成字串的解法 */
bool isPalindrome(int x) {
    if (x < 0) return 0;

    int i = 0, j = x;
    while (x) {
        i = i*10 + x%10;
        x /= 10;
    }

    return i == j;
}
