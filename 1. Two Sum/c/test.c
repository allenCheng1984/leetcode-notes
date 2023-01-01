#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "two_sum.h"

int main()
{
    printf("\n== Test start ==\n");
    int numsSize;
    int target;
    int *returnSize = (int *) malloc(sizeof(int));

    /*
        # Example 1:
        Input: nums = [2,7,11,15], target = 9
        Output: [0,1]
        Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
     */
    numsSize = 4, target = 9, *returnSize = 0;
    int data1[] = {2, 7, 11, 15};
    int *nums1 = (int *) malloc(numsSize * sizeof(int));
    for (int i = 0;i < numsSize;i++)
        nums1[i] = data1[i];

    int *case1 = twoSum(nums1, numsSize, target, returnSize);
    assert(case1[0] == 0);
    assert(case1[1] == 1);
    assert(*returnSize == 2);

    /*
        # Example 2:
        Input: nums = [3,2,4], target = 6
        Output: [1,2]
     */
    numsSize = 3, target = 6, *returnSize = 0;
    int *nums2 = (int *) malloc(numsSize * sizeof(int));
    int data2[] = {3, 2, 4};
    for (int i = 0;i < numsSize;i++)
        nums2[i] = data2[i];

    int *case2 = twoSum(nums2, numsSize, target, returnSize);
    assert(case2[0] == 1);
    assert(case2[1] == 2);
    assert(*returnSize == 2);


    /*
        # Example 3:
        Input: nums = [3,3], target = 6
        Output: [0,1]
     */
    numsSize = 2, target = 6, *returnSize = 0;
    int *nums3 = (int *) malloc(numsSize * sizeof(int));
    int data3[] = {3, 3};
    for (int i = 0;i < numsSize;i++)
        nums3[i] = data3[i];

    int *case3 = twoSum(nums3, numsSize, 6, returnSize);
    assert(case3[0] == 0);
    assert(case3[1] == 1);
    assert(*returnSize == 2);

    /* free all alloced memory */
    free(nums1);
    free(nums2);
    free(nums3);
    free(returnSize);
    free(case1);
    free(case2);
    free(case3);

    printf("== Test finish ==\n");
}
