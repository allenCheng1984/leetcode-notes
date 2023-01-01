from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        prevMap = {}  # val -> index

        for i, n in enumerate(nums):
            diff = target - n
            if diff in prevMap:
                return [prevMap[diff], i]
            prevMap[n] = i

# ----

print("== Test start ==");

nums = [2,7,11,15]
target = 9

case1 = Solution().twoSum(nums, target)
assert(case1 == [0, 1])

# --

nums = [3,2,4]
target = 6

case2 = Solution().twoSum(nums, target)
assert(case2 == [1, 2])

# --

nums = [3, 3]
target = 6

case3 = Solution().twoSum(nums, target)
assert(case3 == [0, 1])

print("== Test start ==");
