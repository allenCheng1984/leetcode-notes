import numpy as np

# class Solution:
#     def longestPalindrome(self, s: str) -> str:
#         longest_palindrom = ''
#         dp = [[False]*len(s) for _ in range(len(s))]

#         for i in range(len(s)):
#             dp[i][i] = True
#             longest_palindrom = s[i]

#         for i in range(len(s)-1,-1,-1):
#             for j in range(i+1,len(s)):
#                 if s[i] == s[j]:  #if the chars mathces
#                     if j-i ==1 or dp[i+1][j-1] is True:
#                         dp[i][j] = True
#                         if len(longest_palindrom) < len(s[i:j+1]):
#                             longest_palindrom = s[i:j+1]

#         return longest_palindrom

class Solution:
    def longestPalindrome(self, s: str) -> str:
        longest_palindrom = ''
        dp = [[False]*len(s) for _ in range(len(s))]
        print("Inital dp table: \n", np.array(dp), "\n")

        # Every isolated char is a palindrome
        for i in range(len(s)):
            dp[i][i] = True
            longest_palindrom = s[i]

        print("dp table: \n", np.array(dp), "\n")

        # filling the dp table
        for i in range(len(s)-1,-1,-1):
            print("i: ", i)
                # j starts from the i location : to only work on the upper side of the diagonal
            for j in range(i+1,len(s)):
                print('\tj: ', j)
                if s[i] == s[j]:  #if the chars mathces
                    # if len slicied sub_string is just one letter if the characters are equal, we can say they are palindomr dp[i][j] =True
                    #if the slicied sub_string is longer than 1, then we should check if the inner string is also palindrom (check dp[i+1][j-1] is True)
                    if j-i ==1 or dp[i+1][j-1] is True:
                        dp[i][j] = True
                        # we also need to keep track of the maximum palindrom sequence
                        if len(longest_palindrom) < len(s[i:j+1]):
                            longest_palindrom = s[i:j+1]

        return longest_palindrom

# s = "acfdfwa"
s = "acfcaca"
# s = "cbbd"
# s = "babad"
# s = "aaa"
# s = "geeks"

test = Solution().longestPalindrome(s)
print(test)
