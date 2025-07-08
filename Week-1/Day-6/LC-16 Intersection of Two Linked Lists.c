/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *ptrA = headA;
    struct ListNode *ptrB = headB;
    
    // Traverse both lists
    while (ptrA != ptrB) {
        ptrA = (ptrA != NULL) ? ptrA->next : headB;
        ptrB = (ptrB != NULL) ? ptrB->next : headA;
    }

    // Either they meet at intersection or both are NULL
    return ptrA;
}
