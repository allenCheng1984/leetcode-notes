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
 * 可運用上述間接指標的技巧，分別指向兩條要合併的串列，從而避免動態記憶體配置:
 */
struct ListNode *partition(struct ListNode *head, int x)
{
    struct ListNode *l2 = NULL;
    struct ListNode **p1 = &head, **p2 = &l2;

    for (struct ListNode *node = head; node; node = node->next) {
        if (node->val < x) {
            *p1 = node;
            p1 = &(*p1)->next;
        } else {
            *p2 = node;
            p2 = &(*p2)->next;
        }
    }

    *p1 = l2;
    *p2 = NULL;
    return head;
}
