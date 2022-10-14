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
 * 頭跟尾兩兩合併
 *
 * 從固定第一條串列改成頭跟尾兩兩合併，直到剩一條為止，
 * 比起前一方法的每次都用愈來愈長的串列跟另一條串列合併，
 * 頭尾合併在多數的情況下兩條串列的長度比較平均，合併會比較快。
 *
 * 當合併完頭尾後，偶數長度會少一半，
 * 奇數長度則為 (listsSize + 1) / 2，
 * 奇數更新的方式也可以用在偶數長度上。
 */

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (listsSize == 0) return NULL;
    for (int i = 1; i < listsSize; i++)
        lists[0] = mergeTwoLists(lists[0], lists[i]);
    return lists[0];
}
