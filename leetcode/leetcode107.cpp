#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> levelOrderBottom_i(TreeNode* root);
vector<vector<int>> levelOrderBottom_r(TreeNode* root);
void dfs(TreeNode* root, vector<vector<int>> &result, int level);

int main(){
    vector<TreeNode*> root_v = {new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))),
                                new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3))};
    for (TreeNode* root : root_v){
        for (vector<int> answer : levelOrderBottom_i(root)){
            for (int ans : answer){
                printf("%d, ", ans);
            }
            printf("\n");
        }
        printf("==========================\n");
    }

    for (TreeNode* root : root_v){
        for (vector<int> answer : levelOrderBottom_r(root)){
            for (int ans : answer){
                printf("%d, ", ans);
            }
            printf("\n");
        }
        printf("==========================\n");
    }

    return 0;
}

vector<vector<int>> levelOrderBottom_i(TreeNode* root) {
    vector<vector<int>> result;
    if (root == NULL) return result;
    queue<TreeNode*> s;
    s.push(root);
    while (!s.empty()){
        int size = s.size();
        vector<int> current;
        for (int i = 0; i < size; i++){
            TreeNode *curnode = s.front();
            current.push_back(curnode->val);
            s.pop();
            if (curnode->left != NULL) s.push(curnode->left);
            if (curnode->right != NULL) s.push(curnode->right);
        }
        result.insert(result.begin(), current);
    }

    return result;
}

vector<vector<int>> levelOrderBottom_r(TreeNode* root) {
    vector<vector<int>> result;
    if (root == NULL) return result;
    dfs(root, result, 0);
    return result;
}

void dfs(TreeNode* root, vector<vector<int>> &result, int level){
    if (root == NULL) return;
    vector<int> current;
    if (level >= result.size()) {
        result.insert(result.begin(), current);
    }

    dfs(root->left, result, level + 1);
    dfs(root->right, result, level + 1);
    result[result.size() - level - 1].push_back(root->val);
}
