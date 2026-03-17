struct ListNode* swapNodes(struct ListNode* head, int k) {

    struct ListNode *first = head;
    struct ListNode *second = head;
    struct ListNode *temp = head;

    // Find kth node from beginning
    for(int i = 1; i < k; i++)
    {
        first = first->next;
    }

    temp = first;

    // Move first to end while moving second
    while(first->next != NULL)
    {
        first = first->next;
        second = second->next;
    }

    // Swap values
    int t = temp->val;
    temp->val = second->val;
    second->val = t;

    return head;
}