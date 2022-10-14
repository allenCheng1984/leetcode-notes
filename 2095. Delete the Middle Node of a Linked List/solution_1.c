struct ListNode {
    int val;
    struct ListNode *next;
};

/* 若不考慮釋放掉中間的節點，可用指標的指標，搭配快慢指標的技巧來實作: */
struct ListNode *deleteMiddle(struct ListNode *head) {
    struct ListNode **indir = &head;
    for (struct ListNode *fast = head; fast && fast->next; fast = fast->next->next)
        indir = &(*indir)->next;
    *indir = (*indir)->next;
    return head;
}
