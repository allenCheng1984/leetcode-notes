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
 * Divide and Conquer (分而治之/各個擊破)
 *
 * 由於 lists 中的串列已排序，可視為 sorted element，直接進行 merge sort:
 *
 */

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (!listsSize)
        return NULL;
    if (listsSize <= 1)
        return *lists;

    int m = listsSize >> 1;
    struct ListNode *left = mergeKLists(lists, m);
    struct ListNode *right = mergeKLists(lists + m, listsSize - m);

    return mergeTwoLists(left, right);
}
