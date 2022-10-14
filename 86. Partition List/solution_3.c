#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

static struct ListNode *new_node()
{
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = 0, node->next = NULL;
    return node;
}

/**
 * 不難發現，在 if-else 中的 p1 跟 p2 是一樣的操作，且 p1 跟 p2 都是指標的指標，
 * 可否進一步精簡程式碼？這時又可利用「指標的指標的指標」來簡化程式碼
 */
struct ListNode *partition(struct ListNode *head, int x)
{
    struct ListNode *l2 = NULL;
    struct ListNode **p1 = &head, **p2 = &l2;

    for (struct ListNode *node = head; node; node = node->next) {
        struct ListNode ***indir = node->val < x ? (&p1): (&p2);
        **indir = node;
        *indir = &(**indir)->next;
    }

    *p1 = l2;
    *p2 = NULL;
    return head;
}
