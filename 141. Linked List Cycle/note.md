
O(n) solution 的解釋
https://leetcode.com/problems/linked-list-cycle/discuss/44669/Fully-Explained!-why-fast-and-slow-can-meet-in-the-cycle

「龜個賽跑」源自於 [Floyd's cycle-finding algorithm](https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_tortoise_and_hare)
https://medium.com/@orionssl/%E6%8E%A2%E7%B4%A2-floyd-cycle-detection-algorithm-934cdd05beb9


視覺化呈現: https://visualgo.net/en/cyclefinding

```java
public class Solution { //java version
    public boolean hasCycle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        while(fast != null && fast.next != null){
            fast = fast.next.next; //2 times
            slow = slow.next;
            if(fast == slow) return true;
        }
        return false;
    }
}
```
