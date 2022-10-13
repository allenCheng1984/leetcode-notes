class Solution:
    def isPalindrome(self, s: str) -> bool:
        # 1. remove all non-alphanumeric characters
        cleaned_s = "".join(c for c in s if c.isalnum()).lower()

        # # equal this:
        # cleaned_s = ""
        # for c in s:
        #     if c.isalnum():
        #         cleaned_s += c.lower()

        # 2. compare each left and right charter
        i = 0
        j = len(cleaned_s) - 1
        while i < j:
            if cleaned_s[i] != cleaned_s[j]:
                return False
            i, j = i+1, j-1
        return True

s = "A man, a plan, a canal: Panama"
# s = "race a car"
# s = " "

test = Solution().isPalindrome(s)
print(test)


"""
Runtime: 46 ms, faster than 84.70% of Python3 online submissions for Valid Palindrome.
Memory Usage: 14.7 MB, less than 54.40% of Python3 online submissions for Valid Palindrome.
"""
