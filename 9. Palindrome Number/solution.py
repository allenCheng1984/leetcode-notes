class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        array = list(str(x))
        i = 0
        j = len(array) - 1
        while i < j:
            if array[i] != array[j]:
                return False
            i, j = i+1, j-1

        return True
