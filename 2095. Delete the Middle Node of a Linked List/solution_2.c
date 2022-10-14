struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * 倘若要釋放中間的節點，可以再用一個指標 prev 跟隨於 indir 之後，
 * 當迴圈走訪完，indir 會指向鏈結串列中間的節點，之後 prev 再指向 indir 的下個節點
 */
struct ListNode *deleteMiddle(struct ListNode *head) {
    struct ListNode **indir = &head;
    for (struct ListNode *fast = head; fast && fast->next; fast = fast->next->next)
        indir = &(*indir)->next;
    struct ListNode *del = *indir;
    *indir = (*indir)->next;
    free(del);
    return head;
}
