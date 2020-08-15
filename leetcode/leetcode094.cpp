#include "TreeNode.h"
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> inorderTraversal_r(TreeNode* root);
void helper(TreeNode* root, vector<int> &result);
vector<int> inorderTraversal_i(TreeNode* root);

int main(){
    TreeNode *root = new TreeNode(1, NULL, new TreeNode(2, new TreeNode(3), NULL));
    for (int ans : inorderTraversal_r(root)){
        printf("%d, ", ans);
    }
    printf("\n");
    for (int ans : inorderTraversal_i(root)){
        printf("%d, ", ans);
    }
    // for (int ans : inorderTraversal(root)){
    //     printf("%d, ", ans);
    // }
    return 0;
}

// Recursive
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> inorderTraversal_r(TreeNode* root) {
    vector<int> result;
    helper(root, result);
    return result;
}

void helper(TreeNode* root, vector<int> &result){
    if (root == NULL) return;
    if (root->left != NULL){
        helper(root->left, result);
    }
    result.push_back(root->val);
    if (root->right != NULL){
        helper(root->right, result);
    }
}

// Iterative
// Time Complexity: O(n)
// Space Complexity: O(1)
vector<int> inorderTraversal_i(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode *current = root;
    while(current != NULL || !s.empty()){
        while (current != NULL){
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        result.push_back(current->val);
        current = current->right;
    }
    return result;
}
