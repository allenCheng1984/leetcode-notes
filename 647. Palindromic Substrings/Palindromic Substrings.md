## Description:
[Question Link](https://leetcode.com/problems/palindromic-substrings/)

Given a string `s`, return the number of **palindromic substrings** in it.

A string is a **palindrome** when it reads the same backward as forward.

A **substring** is a contiguous sequence of characters within the string.

### Example 1:
```
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
```

### Example 2:
```
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
```

### Constraints:
- 1 <= s.length <= 1000
- s consists of lowercase English letters.

---

## 解題方向：

1. 每個字串的排列組合數量為梯形公式 (1 + len(s)) * len(s) / 2
2. 二個字元 => 3 種, 四個字元 => 10 種 ...
3. 可以用 slide window 的方式來理解每個組合的組成方式
4. 寫出以下的迴圈檢查，並紀錄是否為 palindrome
  * 每個單一字元都一定是 palindrome (`table[i][i]` 都設為 True)
  * 每雙字元的 string 只需要檢查 `s[i] == s[i+1]` => `table[i][i+1] = s[i] == s[i+1]`
  * 三字元以上(例如 `s[0:2]`)，先檢查前一回的檢查 (`s[1:1]`) 在 table 表上是否紀錄為 true (代表為 palindrome)
    * 再檢查頭尾字元即可判斷是否為 palindrome, 並在 table[0:2] 上紀錄 True/False

範例1:
s = 'abcd' 的比較表：

|     |  a  |   b |   c |    d |
|:---:|:---:| ---:| ---:| ----:|
|  a  |  a  |  ab | abc | abcd |
|  b  |     |   b |  bc |  bcd |
|  c  |     |     |   c |   cd |
|  d  |     |     |     |    d |


結果 => 4 種組合為 palindrome
( 'a', 'b', 'c', 'd' )

範例2:
s = 'aaaa' 的比較表：

|     |  a  |   a |   a |    a |
|:---:|:---:| ---:| ---:| ----:|
|  a  |  a  |  aa | aaa | aaaa |
|  a  |     |   a |  aa |  aaa |
|  a  |     |     |   a |   aa |
|  a  |     |     |     |    a |

結果 => 10 種組合為 palindrome
```
 'a', 'aa', 'aaa', 'aaaa',
       'a',  'aa',  'aaa',
              'a',   'aa',
                      'a',
```
