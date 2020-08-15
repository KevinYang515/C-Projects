#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isSymmetric_r(TreeNode* root);
bool helper_r(TreeNode* left, TreeNode* right);
bool isSymmetric_i(TreeNode* root);

int main(){
    vector<TreeNode*> root_v = {new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3))), 
                                new TreeNode(1, new TreeNode(2, NULL, new TreeNode(3)), new TreeNode(2, NULL, new TreeNode(3)))};
    for (TreeNode* root : root_v){
        printf("%s, ", isSymmetric_r(root)?"true":"false");
    }

    return 0;
}

// Recursive
// Time Complexity: O(n)
// Space Complexity: O(n)
bool isSymmetric_r(TreeNode* root) {
    return helper_r(root, root);
}

bool helper_r(TreeNode* left, TreeNode* right){
    if (left == NULL && right == NULL) return true;
    if (left == NULL || right == NULL) return false;
    return (left->val == right->val) && 
           helper_r(left->left, right->right) &&
           helper_r(left->right, right->left);
}

// Iterative
// Time Complexity: O(n)
// Space Complexity: O(n)
bool isSymmetric_i(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(root);
    while (!q.empty()){
        TreeNode* left = q.front();
        q.pop();
        TreeNode* right = q.front();
        q.pop();
        if (left == NULL && right == NULL) continue;
        if (left == NULL || right == NULL) return false;
        if (left->val != right->val) return false;
        q.push(left->right);
        q.push(right->left);
        q.push(left->left);
        q.push(right->right);
    }

    return true;
}
