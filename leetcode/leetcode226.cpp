#include "TreeNode.h"
#include <iostream>
#include <queue>

using namespace std;

TreeNode* invertTree_i(TreeNode* root);
TreeNode* invertTree_r(TreeNode* root);

int main(){
    TreeNode *root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7, new TreeNode(6), new TreeNode(9)));
    invertTree_i(root);
    invertTree_r(root);
    return 0;
}

// Iterative
// Time Complexity: O(n)
// Space Complexity: O(n)
TreeNode* invertTree_i(TreeNode* root) {
    if (root == NULL) return root;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode *current = q.front();
        q.pop();
        TreeNode *temp = current->left;
        current->left = current->right;
        current->right = temp;
        if (current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
    }
    return root;
}

// Recursive
// Time Complexity: O(n)
// Space Complexity: O(n)
TreeNode* invertTree_r(TreeNode* root) {
    if (root == NULL) return root;
    TreeNode *left = invertTree_r(root->left);
    TreeNode *right = invertTree_r(root->right);
    root->right = left;
    root->left = right;

    return root;
}
