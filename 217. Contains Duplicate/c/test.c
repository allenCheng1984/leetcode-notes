#include <stdio.h>
#include <assert.h>
#include "contains_duplicate.h"

int main()
{
    printf("\n== Test start ==\n");

    int case1[] = {1, 2, 3, 1};
    assert(containsDuplicate(case1, 4) == true);

    int case2[] = {1, 2, 3, 4};
    assert(containsDuplicate(case2, 4) == false);

    int case3[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    assert(containsDuplicate(case3, 10) == true);

    printf("== Test finish ==\n");
}
