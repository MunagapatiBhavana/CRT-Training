struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
struct ListNode* removeNodes(struct ListNode* head) {
    head = reverse(head);
    
    struct ListNode* curr = head;
    int maxVal = curr->val;
    
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->val < maxVal) {
            struct ListNode* temp = curr->next;
            curr->next = temp->next;
            free(temp);
        } else {
            curr = curr->next;
            maxVal = curr->val;
        }
    }

    head = reverse(head);
    return head;
}
