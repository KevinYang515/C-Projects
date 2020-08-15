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
}

// Recursive
// Time Complexity: O(n)
// Space Complexity: O(n)
bool isSymmetric_r(TreeNode* root) {

}

bool helper_r(TreeNode* left, TreeNode* right){

}

bool isSymmetric_i(TreeNode* root) {

}
