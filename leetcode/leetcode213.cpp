#include <iostream>
#include <vector>

using namespace std;

int rob_1(vector<int>& nums);
int rob_2(vector<int>& nums);

int main(){
    vector<vector<int>> nums_v = {{2,3,2}, {1,2,3,1}};  //3, 4
    for (vector<int> nums : nums_v){
        printf("%d, ", rob_1(nums));
    }
    printf("\n========================\n");
    for (vector<int> nums : nums_v){
        printf("%d, ", rob_2(nums));
    }
    
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
int rob_1(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    vector<int> f_rob(nums.size() - 1, 0);
    vector<int> f_not_rob(nums.size() - 1, 0);
    vector<int> s_rob(nums.size() - 1, 0);
    vector<int> s_not_rob(nums.size() - 1, 0);
    f_rob[0] = nums[0];
    s_rob[0] = nums[1];
    for (int i = 1; i < nums.size() - 1; i++){
        f_rob[i] = f_not_rob[i - 1] + nums[i];
        f_not_rob[i] = max(f_rob[i - 1], f_not_rob[i - 1]);
        s_rob[i] = s_not_rob[i - 1] + nums[i + 1];
        s_not_rob[i] = max(s_rob[i - 1], s_not_rob[i - 1]);
    }

    return max(max(f_rob[nums.size() - 2], f_not_rob[nums.size() - 2]), 
                max(s_rob[nums.size() - 2], s_not_rob[nums.size() - 2]));
}

// Time Complexity: O(n)
// Space Complexity: O(1)
int rob_2(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    int f_rob = 0, f_not_rob = 0;
    int s_rob = 0, s_not_rob = 0;

    for (int i = 0; i < nums.size() - 1; i++){
        int f_prev = max(f_rob, f_not_rob);
        f_rob = f_not_rob + nums[i];
        f_not_rob = f_prev;

        int s_prev = max(s_rob, s_not_rob);
        s_rob = s_not_rob + nums[i + 1];
        s_not_rob = s_prev;
    }

    return max(max(f_rob, f_not_rob), max(s_rob, s_not_rob));
}
