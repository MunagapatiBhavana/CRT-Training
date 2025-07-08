## Day 6
---

## 🧠 Topics Covered

1. [Delete Node at Beginning](#1-delete-node-at-beginning)
2. [Delete Node at End](#2-delete-node-at-end)
3. [Delete Node at a Given Position](#3-delete-node-at-a-given-position)
4. [Reverse a Linked List](#4-reverse-a-linked-list)
5. [Reverse a Linked List Until Value `k`](#5-reverse-until-value-k)
6. [Skip `k` Nodes and Print Remaining](#6-skip-k-and-print-remaining)
7. [Reverse Every `k` Nodes](#7-reverse-every-k-nodes)
8. [Detect Cycle in a Linked List](#8-detect-cycle-in-a-linked-list)
9. [Find Starting Node of a Cycle](#9-find-starting-node-of-cycle)

---

## 1. Delete Node at Beginning

struct Node {

    int data;
    struct Node* next;
};

void deleteAtBeginning(struct Node** head) {

    if (*head == NULL) return;
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}


## 2. Delete Node at End

void deleteAtEnd(struct Node** head) {

    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}


## 3. Delete Node at a Given Position

void deleteAtPosition(struct Node** head, int pos) {

    if (*head == NULL || pos < 1) return;
    if (pos == 1) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) return;
    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

## 4. Reverse a Linked List

struct Node* reverseList(struct Node* head) {

    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

## 5. Reverse Until Value k

struct Node* reverseUntilK(struct Node* head, int k) {

    struct Node* prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL && curr->data != k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = curr;
    return prev;
}


## 6. Skip k and Print Remaining

void printAfterK(struct Node* head, int k) {

    int count = 0;
    while (head != NULL && count < k) {
        head = head->next;
        count++;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

## 7. Reverse Every k Nodes

struct Node* reverseEveryK(struct Node* head, int k) {

    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    int count = 0;
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
        head->next = reverseEveryK(next, k);
    return prev;
}

## 8. Detect Cycle in a Linked List

bool hasCycle(struct Node* head) {

    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

## 9. Find Starting Node of Cycle

struct Node* detectCycleStart(struct Node* head) {

    struct Node* slow = head;
    struct Node* fast = head;
    bool hasCycle = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }
    if (!hasCycle) return NULL;
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

## 10. Adding 2 values

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode dummy;
    struct ListNode* temp = &dummy;
    dummy.next = NULL;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        temp->next = createNode(sum % 10);
        temp = temp->next;
    }

    return dummy.next;
}

### 📌 Notes
All code is written in C.

Ensure you have a main() function to create and test these functions.

Use appropriate memory management (malloc, free) for dynamic node creation.


