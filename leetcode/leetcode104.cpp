#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maxDepth_r(TreeNode* root);
int maxDepth_i(TreeNode* root);

int main(){
    vector<TreeNode*>  root_v = {new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))), 
                                 new TreeNode(1, new TreeNode(2), NULL)};
    // 3, 2
    for (TreeNode* root : root_v){
        printf("%d, ", maxDepth_r(root));
    }
    printf("\n===============================================\n");
    for (TreeNode* root : root_v){
        printf("%d, ", maxDepth_i(root));
    }
    return 0;
}

// Recursive
// Time Complexity: O(n)
// Space Complexity: O(n) or O(logn)
int maxDepth_r(TreeNode* root) {
    if (root == NULL) return 0;
    return max(maxDepth_r(root->left), maxDepth_r(root->right)) + 1;
}

// Iterative
// Time Complexity: O(n)
// Space Complexity: O(n)
int maxDepth_i(TreeNode* root) {
    if (root == NULL) return 0;
    int depth = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        int size = q.size();
        for (int i = 0; i < size; i++){
            TreeNode* current = q.front();
            q.pop();
            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
        }
        depth ++;
    }

    return depth;
}
