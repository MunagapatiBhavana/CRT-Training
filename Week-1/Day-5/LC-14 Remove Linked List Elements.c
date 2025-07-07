struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create a dummy node to simplify removal of head node
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* current = dummy;

    while (current->next != NULL) {
        if (current->next->val == val) {
            // Remove the node
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    struct ListNode* newHead = dummy->next;
    free(dummy);  // Free the dummy node
    return newHead;
}
