#include <stdlib.h>



struct ListNode* deleteMiddle(struct ListNode* head) {
    // If there's only one node, delete it and return NULL
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *prev = NULL;

    // Use slow and fast pointers to find the middle node
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // Delete the middle node
    prev->next = slow->next;
    free(slow);

    return head;
}
