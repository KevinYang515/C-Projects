#include "ListNode.h"
#include <iostream>

using namespace std;

ListNode* reverseList_i(ListNode* head);

int main(){
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *result_1 = reverseList_i(head);
    ListNode *result_2 = reverseList_r(head);
    
    while (result_1 != NULL){
        printf("%d, ", result_1->val);
        result_1 = result_1->next;
    }
    printf("\n");
    while (result_2 != NULL){
        printf("%d, ", result_2->val);
        result_2 = result_2->next;
    }

    return 0;
}

// Iterative
// Time Complexity: O(n)
// Space Complexity: O(1)
ListNode* reverseList_i(ListNode* head) {
    if (head == NULL) return head;
    ListNode *prev = NULL, *current = head;

    while (head != NULL){
        ListNode *temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    return prev;
}

// Recursive
// Time Complexity: O(n)
// Space Complexity: O(n)
ListNode* reverseList_r(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode *p = reverseList_r(head->next);
    head->next->next = head;
    head->next = NULL;

    return p;
}
