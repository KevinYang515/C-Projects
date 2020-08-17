#include "TreeNode.h"
#include <vector>
#include <iostream>
#include <stack>
#include <float.h>

using namespace std;

bool isValidBST(TreeNode* root);

int main(){
    vector<TreeNode*> root_v = {new TreeNode(2, new TreeNode(1), new TreeNode(3)), 
                                new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)))};
    for (TreeNode* root : root_v){
        printf("%s, ", isValidBST(root) ? "true" : "false");
    }
    
    return 0;
}

bool isValidBST(TreeNode* root) {
    if (root == NULL) return true;
    double value = -DBL_MAX;
    stack<TreeNode*> s;
    TreeNode* current = root;
    while (!s.empty() || current != NULL){
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        if (value >= current->val) return false;
        value = current->val;
        current = current->right;
    }

    return true;
}
