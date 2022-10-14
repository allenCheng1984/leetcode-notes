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

struct ListNode *partition(struct ListNode *head, int x)
{
    struct ListNode *l1 = new_node(), *l2 = new_node();

    struct ListNode *ptr1 = l1, *ptr2 = l2;
    for (; head; head = head->next) {
        if (head->val < x) {
            ptr1->next = head;
            ptr1 = ptr1->next;
        } else {
            ptr2->next = head;
            ptr2 = ptr2->next;
        }
    }

    ptr2->next = NULL;
    ptr1->next = l2->next;
    return l1->next;
}
