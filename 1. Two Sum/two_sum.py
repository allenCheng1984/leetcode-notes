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

nums = [2,7,11,15]
target = 9

test = Solution().twoSum(nums, target)
print(test)
