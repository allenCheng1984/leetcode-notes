#include <stdio.h>
#include <assert.h>
#include "valid_anagram.h"

int main()
{
    printf("\n== Test start ==\n");

    char *s1 = "anagram";
    char *t1 = "nagaram";
    assert(isAnagram(s1, t1) == true);

    char *s2 = "rat";
    char *t2 = "car";
    assert(isAnagram(s2, t2) == false);

    printf("== Test finish ==\n");
}
