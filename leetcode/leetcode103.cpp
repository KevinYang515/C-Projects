#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root);

int main(){
    vector<TreeNode*> root_v = {new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)))};
    for (TreeNode* root : root_v){
        for (vector<int> answer : zigzagLevelOrder(root)){
            for (int ans : answer){
                printf("%d, ", ans);
            }
        }
        printf("\n========================\n");
    }
}

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == NULL) return result;
    int convert = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size; i++){
            TreeNode* current = q.front();
            q.pop();
            if (convert == 0){
                temp.push_back(current->val);
            }else {
                temp.insert(temp.begin(), current->val);
            }
            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
        }
        convert = !convert;
        result.push_back(temp);
    }

    return result;
}
