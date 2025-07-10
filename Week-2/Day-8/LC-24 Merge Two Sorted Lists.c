/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Create a dummy node to start the merged list
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    // Traverse both lists and pick the smaller value each time
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Append the remaining nodes from either list
    if (list1 != NULL) tail->next = list1;
    if (list2 != NULL) tail->next = list2;

    return dummy.next;  // Return head of merged list (skipping dummy)
}
