## Description:
[Question Link](https://leetcode.com/problems/valid-palindrome/submissions/)
A phrase is a **palindrome** if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` if it is a **palindrome**, or false otherwise.


### Example 1:
```
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
```

### Example 2:
```
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
```

### Example 3:
```
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
```

---

## 解題方向：

1. 排除掉所有非字母與數字的字元
2. 將字母轉小寫
3. 設定一個迴圈，每圈比較對稱的左右二個字元，逐步縮小
  * 如果有不同的，就直接回傳 false
  * 直到最後一圈 (i < j) 都一致後才回傳 True
