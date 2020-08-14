#include "ListNode.h"
#include <iostream>

using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

int main(){
    ListNode *list1 = new ListNode(2, new ListNode(4, new ListNode(3))), 
             *list2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    ListNode *result = addTwoNumbers(list1, list2);

    while (result != NULL){
        printf("%d, ", result->val);
        result = result->next;
    }

    return 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(0), *p = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0){
        if (l1 != NULL){
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL){
            carry += l2->val;
            l2 = l2->next;
        }
        p->next = new ListNode(carry % 10);
        carry /= 10;
        p = p->next;
    }
    return dummy->next;
}