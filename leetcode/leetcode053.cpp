#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums);

int main(){
    vector<vector<int>> nums_v = {{-2,1,-3,4,-1,2,1,-5,4}, {1}, {-2, -1}};

    for (vector<int> nums : nums_v){
        printf("%d, ", maxSubArray(nums));
    }

    return 0;
}

int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    int max_val = nums[0], result = nums[0];
    for (int i = 1; i < nums.size(); i++){
        if (max_val > 0) {
            max_val = max_val + nums[i];
        }else{
            max_val = nums[i];
        }
        result = max(result, max_val);
    }

    return result;
}
