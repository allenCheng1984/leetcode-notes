
O(n) solution 的解釋
https://leetcode.com/problems/linked-list-cycle/discuss/44669/Fully-Explained!-why-fast-and-slow-can-meet-in-the-cycle

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
