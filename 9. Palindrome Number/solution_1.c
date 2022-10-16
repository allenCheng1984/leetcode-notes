#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) return false;

    /**
     * Constraints: -2^31 <= x <= 2^31 - 1
     * => -2147483648 ~ 2147483647
     * 數字長度 11 字元 + 1 負數 + 1 結尾字元(\0) = 最多 13 個字元,
     */
    char str[13];
	int len = sprintf(str, "%d", x); /* ref: https://www.tutorialspoint.com/c_standard_library/c_function_sprintf.htm */

	for (int i = 0; i <= (len/2); ++i) {
		if (str[i] != str[len-i-1])
            return false;
	}

	return true;
}
