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
 * 分段合併
 *
 * 除了頭尾合併，還可以分段存取下個要合併的串列，
 * 分別合併 lists[i] 跟 lists[i + interval]，為確保內層迴圈不會重複存取，
 * 索引值 i 會更新為 i + interval * 2，
 * 當內層迴圈合併完之後會把結果分別存到
 * lists[interval*2],
 * lists[interval*4],
 * lists[interval*6]
 *
 * 因此，外層迴圈在更新 interval 時，也要變成 2 倍，以確保進入內層迴圈存取 lists 的正確位置。
 *
 */

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (listsSize == 0) return NULL;

    for (int interval = 1; interval < listsSize; interval *= 2)
        for (int i = 0; i + interval < listsSize; i += interval * 2) {
            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
        }

    return lists[0];
}
