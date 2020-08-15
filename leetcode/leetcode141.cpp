#include "ListNode.h"
#include <iostream>
#include <vector>

using namespace std;

bool hasCycle(ListNode *head);

int main(){
    vector<ListNode*> head_v = {new ListNode(3, new ListNode(2, new ListNode(0, new ListNode(-4)))),
                                new ListNode(1, new ListNode(2)),
                                new ListNode(1),
                                new ListNode(1, new ListNode(2))};
    head_v[0]->next->next->next->next = head_v[0]->next;
    head_v[1]->next->next = head_v[1];
    for (ListNode* head : head_v){
        printf("%s, ", hasCycle(head)?"true":"false");
    }

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
bool hasCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) return false;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (slow != fast){
        if (fast == NULL || fast->next == NULL) return false;
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}
