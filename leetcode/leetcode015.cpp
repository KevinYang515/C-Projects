#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);

int main(){
    vector<vector<int>> nums_v = {{-1, 0, 1, 2, -1, -4}};
    for (vector<int> nums : nums_v){
        for (vector<int> answer : threeSum(nums)){
            for (int ans : answer){
                printf("%d, ", ans);
            }
            printf("\n");
        }
        printf("=======================\n");
    }

    return 0;
}

// Time Complexity: O(n^(k - 1)) (e.g., 4Sum: O(n^3), 3Sum: O(n^2), 2Sum:O(n))
// Space Complexity: O(1)
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.empty() || nums.size() < 3) return result;
    sort(nums.begin(), nums.end());
    vector<int> num_set(3);
    for (int i = 0; i < nums.size() - 2; i++){
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1])){
            int low = i + 1, high = nums.size() - 1;
            while (low < high){
                int sum = nums[i] + nums[low] + nums[high];
                if (sum == 0){
                    num_set[0] = nums[i], num_set[1] = nums[low], num_set[2] = nums[high];
                    result.push_back(num_set);
                    while (low < high && nums[low] == nums[low+1]) low++;
                    while (low < high && nums[high] == nums[high-1]) high--;
                    low++, high--;
                }else if (sum < 0){
                    while (low < high && nums[low] == nums[low+1]) low++;
                    low++;
                }else{
                    while (low < high && nums[high] == nums[high-1]) high--;
                    high--;
                }
            }
        }
    }
    return result;
}
