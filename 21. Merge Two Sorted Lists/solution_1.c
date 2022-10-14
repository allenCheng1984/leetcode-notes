
/* 一般的解法 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *L1, struct ListNode *L2) {
    struct ListNode *head = malloc(sizeof(struct ListNode));
    struct ListNode *ptr = head;
    while (L1 && L2) {
        if (L1->val < L2->val) {
            ptr->next = L1;
            L1 = L1->next;
        } else {
            ptr->next = L2;
            L2 = L2->next;
        }
        ptr = ptr->next;
    }
    ptr->next = L1 ? L1 : L2;
    return head->next;
}
