#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target);

int main() {
    vector<vector<int>> nums_v = {{1, 0, -1, 0, -2, 2}, {-1, 0, 1, 2, -1, -4}, {-3,-2,-1,0,0,1,2,3}};
    vector<int> target_v = {0, -1, 0};
    for (int i = 0; i < nums_v.size(); i++){
        for (vector<int> answer : fourSum(nums_v[i], target_v[i])){
            for (int ans : answer) {
                printf("%d, ", ans);
            }
            printf("\n");
        }
        printf("============================\n");
    }
    return 0;
}

// Time Complexity: O(n^(k - 1)) (e.g., 4Sum: O(n^3), 3Sum: O(n^2), 2Sum:O(n))
// Space Complexity: O(1)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    if (nums.empty() || nums.size() < 4) return result;
    vector<int> num_set(4);
    sort(begin(nums), end(nums));
    for (int i = 0; i < nums.size() - 3; i++){
        if (i == 0 || (i > 0 && (nums[i] != nums[i - 1]))){
            for (int j = i + 1; j < nums.size() - 2; j++){
                if ((j == i + 1) || (j > i + 1 && (nums[j] != nums[j - 1]))){
                    int low = j + 1, high = nums.size() - 1;
                
                    while (low < high){
                        int sum = nums[i] + nums[j] + nums[low] + nums[high];
                        if (sum == target){
                            num_set[0] = nums[i], num_set[1] = nums[j];
                            num_set[2] = nums[low], num_set[3] = nums[high];
                            result.push_back(num_set);
                            while (low < high && nums[low] == nums[low + 1]) low++;
                            while (low < high && nums[high] == nums[high - 1]) high--;
                            low ++, high --;
                        }else if (sum < target){
                            while (low < high && nums[low] == nums[low + 1]) low++;
                            low ++;
                        }else {
                            while (low < high && nums[high] == nums[high - 1]) high--;
                            high --;
                        }
                    }
                }
            }
        }
    }

    return result;
}
