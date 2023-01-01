#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "two_sum.h"

int main()
{
    printf("\n== Test start ==\n");

    int *returnSize;
    int numsSize;
    /*
        # Example 1:
        Input: nums = [2,7,11,15], target = 9
        Output: [0,1]
        Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
     */
    numsSize = 4;
    int *nums1;
    nums1 = (int *) malloc(numsSize * sizeof(int));
    nums1[0] = 2;
    nums1[1] = 7;
    nums1[2] = 11;
    nums1[3] = 15;

    int *case1 = twoSum(nums1, numsSize, 9, returnSize);
    assert(case1[0] == 0);
    assert(case1[1] == 1);
    assert(*returnSize == 2);
    free(nums1);
    *returnSize = 0;


    /*
        # Example 2:
        Input: nums = [3,2,4], target = 6
        Output: [1,2]
     */
    numsSize = 3;
    int *nums2;
    nums2 = (int *) malloc(numsSize * sizeof(int));
    nums2[0] = 3;
    nums2[1] = 2;
    nums2[2] = 4;

    int *case2 = twoSum(nums2, numsSize, 6, returnSize);
    assert(case2[0] == 1);
    assert(case2[1] == 2);
    assert(*returnSize == 2);
    free(nums2);
    *returnSize = 0;

    /*
        # Example 3:
        Input: nums = [3,3], target = 6
        Output: [0,1]
     */
    numsSize = 2;
    int *nums3;
    nums3 = (int *) malloc(numsSize * sizeof(int));
    nums3[0] = 3;
    nums3[1] = 3;

    int *case3 = twoSum(nums3, numsSize, 6, returnSize);
    assert(case3[0] == 0);
    assert(case3[1] == 1);
    assert(*returnSize == 2);
    free(nums3);
    *returnSize = 0;

    printf("== Test finish ==\n");
}
