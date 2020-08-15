#include  "ListNode.h"
#include <vector>
#include <iostream>

using namespace std;

ListNode* sortList(ListNode* head);
ListNode* merge(ListNode* left, ListNode* right);

int main(){
    vector<ListNode*> head_v = {new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3)))),
                                new ListNode(-1, new ListNode(5, new ListNode(3, new ListNode(4, new ListNode(0)))))};

    for (ListNode* head : head_v){
        ListNode* answer = sortList(head);
        while (answer != NULL){
            printf("%d, ", answer->val);
            answer = answer->next;
        }
        printf("\n");
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = slow->next;
    slow->next = NULL;

    ListNode* first = sortList(head);
    ListNode* second = sortList(fast);

    return merge(first, second);
}

ListNode* merge(ListNode* left, ListNode* right){
    if (left == NULL) return right;
    else if (right == NULL) return left;

    ListNode *dummy = new ListNode(0), *result = dummy;

    while (left != NULL && right != NULL){
        if (left->val <= right->val){
            result->next = left;
            left = left->next;
        }else{
            result->next = right;
            right = right->next;
        }
        result = result->next;
    }

    if (left != NULL){
        result->next = left;
    }else{
        result->next = right;
    }

    return dummy->next;
}
