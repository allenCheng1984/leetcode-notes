import numpy as np

# class Solution:
#     def countSubstrings(self, s: str) -> int:
#         # if s not present => 0
#         if not s: return 0

#         n = len(s)
#         count = 0
#         table = []
#         for i in range(n):
#             table.append([False for x in range(n)])

#         # Every isolated char is a palindrome
#         for i in range(n):
#             table[i][i] = True
#             count += 1


#          # Check for a window of size 2
#         for i in range(n-1):
#             if s[i] == s[i+1]:
#                 table[i][i+1] = True
#                 count += 1


#         # Check windows of size 3 and more
#         for k in range(3, n+1):
#             for i in range(n-k+1):
#                 j = i+k-1
#                 if table[i+1][j-1] and s[i] == s[j]:
#                     table[i][j] = True
#                     count += 1

#         return count


# with print
class Solution:
    def countSubstrings(self, s: str) -> int:
        # if s not present => 0
        if not s: return 0

        n = len(s)
        count = 0
        table = []
        # 建立一個 table array 紀錄所有排列組合是否為 palindrome
        for i in range(n):
            table.append([False for x in range(n)])

        # Every isolated char is a palindrome
        print("Every isolated char is a palindrome")
        print(f"s = {s}, length: {n}")
        for i in range(n):
            table[i][i] = True
            count += 1

        print("\tcount1: ", count)

         # Check for a window of size 2
        print("Check for a window of size 2")
        for i in range(n-1):
            if s[i] == s[i+1]:
                table[i][i+1] = True
                print(f"\t {s[i]}{s[i+1]}")
                count += 1

        print("\tcount2: ", count)

        # Check windows of size 3 and more
        for k in range(3, n+1):
            print(f"Check for a windows of size {k}")
            print("compare table: \n", np.array(table))

            for i in range(n-k+1):
                j = i+k-1
                print(f"\t{table[i+1][j-1] and s[i] == s[j]}\t=> i: {i} ({s[i]}), j: {j} ({s[j]}), last compare in [{i+1}][{j-1}]: {table[i+1][j-1]}")

                # table[i+1][j-1] was identified palindrome record in previous check
                if table[i+1][j-1] and s[i] == s[j]:
                    table[i][j] = True
                    count += 1

            print("")

        print("====\nfinal count: ", count)
        print("final compare table: \n", np.array(table), "\n")

        return count

# s = "acfdfwa"
# s = "acfdswa"
# s = "aaaaba"
s = "aaaa"
# s = "aaa"
# s = "geeks"

test = Solution().countSubstrings(s)
print(test)
