#include "ListNode.h"
#include <iostream>
#include <vector>

using namespace std;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

int main(){
    vector<ListNode*> l1_v = {new ListNode(1, new ListNode(2, new ListNode(4)))};
    vector<ListNode*> l2_v = {new ListNode(1, new ListNode(3, new ListNode(4)))};

    for (int i = 0; i < l1_v.size(); i++){
        ListNode* answer = mergeTwoLists(l1_v[i], l2_v[i]);
        while (answer != NULL){
            printf("%d, ", answer->val);
            answer = answer->next;
        }
        printf("\n");
    }

    return 0;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    else if (l2 == NULL) return l1;
    ListNode *dummy = new ListNode(0), *result = dummy;
    while (l1 != NULL && l2 != NULL){
        if (l1->val > l2->val){
            result->next = new ListNode(l2->val);
            result = result->next;
            l2 = l2->next;
        }else {
            result->next = new ListNode(l1->val);
            result = result->next;
            l1 = l1->next;
        }
    }

    if (l1 != NULL){
        result->next = l1;
    }else{
        result->next = l2;
    }

    return dummy->next;
}