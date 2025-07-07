struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // Store next node
        curr->next = prev;   // Reverse current node's pointer
        prev = curr;         // Move prev to current node
        curr = next;         // Move to next node
    }

    return prev;  // New head of reversed list
}
