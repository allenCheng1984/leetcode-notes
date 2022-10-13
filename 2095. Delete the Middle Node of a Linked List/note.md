```c
struct ListNode* deleteMiddle(struct ListNode* head){
    if(head->next==NULL){return NULL;}

    struct ListNode *fast_ptr = head;
    struct ListNode *slow_ptr = head;
    struct ListNode *tail = NULL;

    while(fast_ptr && fast_ptr->next){
        tail = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    fast_ptr = slow_ptr;
    slow_ptr = slow_ptr->next;
    tail->next = slow_ptr;

	  free(fast_ptr);

    return head;
}
```

```c
struct ListNode* deleteMiddle(struct ListNode* head){
	struct ListNode** slow = &head;
    for (struct ListNode* fast = head; fast && fast->next;) {
        fast = fast->next->next;
        slow = &((*slow)->next);
    }
    struct ListNode* tmp = *slow;
    *slow = (*slow)->next;
    free(tmp);
    return head;
}
```
