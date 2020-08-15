#include "TreeNode.h"
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> levelOrder(TreeNode* root);

int main(){
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    vector<vector<int>> result = levelOrder(root);
    
    for (vector<int> answer : result){
        for (int ans : answer){
            printf("%d, ", ans);
        }
        printf("\n");
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == NULL) return result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size; i++){
            TreeNode* current = q.front();
            temp.push_back(current->val);
            q.pop();
            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
        }
        result.push_back(temp);
    }
    return result;
}
