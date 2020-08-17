#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> permute(vector<int>& nums);
void permute_helper(vector<int> &nums, int m, vector<int> &current, vector<vector<int>> &result);

int main(){
    vector<vector<int>> nums_v = {{1, 2, 3}};
    for (vector<int> nums : nums_v){
        for (vector<int> answer : permute(nums)){
            for (int ans : answer){
                printf("%d, ", ans);
            }
            printf("\n");
        }
        printf("===================\n");
    }

    return 0;
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.empty()) result;
    vector<int> current;
    permute_helper(nums, 0, current, result);
    return result;
}

void permute_helper(vector<int> &nums, int m, vector<int> &current, vector<vector<int>> &result){
    if (current.size() == nums.size()){
        result.push_back(current);
        return;
    }

    for (int i = 0; i <= current.size(); i++){
        current.insert(current.begin() + i, nums[m]);
        permute_helper(nums, m + 1, current, result);
        current.erase(current.begin() + i);
    }
}
