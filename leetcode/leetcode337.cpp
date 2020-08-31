#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int rob(TreeNode* root);
vector<int> rob_helper(TreeNode* root);

int main(){
    vector<TreeNode*> root_v = {new TreeNode(3, new TreeNode(2, NULL, new TreeNode(3)), new TreeNode(3, NULL, new TreeNode(1))), 
                                new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(3)), new TreeNode(5, NULL, new TreeNode(1)))};
    // 7, 9
    for (TreeNode* root : root_v){
        printf("%d, ", rob(root));
    }
    return 0;
}

int rob(TreeNode* root) {
    vector<int> result = rob_helper(root);
    return max(result[0], result[1]);
}

vector<int> rob_helper(TreeNode* root){
    vector<int> result(2, 0);
    if (root == NULL) return result;
    // result[0] for not rob
    // result[1] for rob
    vector<int> left = rob_helper(root->left);
    vector<int> right = rob_helper(root->right);
    result[0] = max(left[0], left[1]) + max(right[0], right[1]);
    result[1] = left[0] + right[0] + root->val;

    return result;
}
