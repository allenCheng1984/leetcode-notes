#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/* from LC 21. Merge Two Sorted Lists */
struct ListNode *mergeTwoLists(struct ListNode *L1, struct ListNode *L2) {
    struct ListNode *head = NULL, **ptr = &head, **node;

    for (node = NULL; L1 && L2; *node = (*node)->next) {
        node = (L1->val < L2->val) ? &L1: &L2;
        *ptr = *node;
        ptr = &(*ptr)->next;
    }
    *ptr = (struct ListNode *)((uintptr_t) L1 | (uintptr_t) L2);
    return head;
}

/**
 * naive(純真式解法)
 *
 * 直觀地用第一條串列接上剩下的串列，這樣會導致 lists[0] 愈來愈長，
 * 立即會遇到的問題是：多數的情況下合併速度會愈來愈慢。
 */

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (listsSize == 0) return NULL;
    for (int i = 1; i < listsSize; i++)
        lists[0] = mergeTwoLists(lists[0], lists[i]);
    return lists[0];
}
