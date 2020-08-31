#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums);

int main(){
    vector<vector<int>> nums_v = {{1,2,3,1}, {2,7,9,3,1}};  //4, 12
    for (vector<int> nums : nums_v){
        printf("%d, ", rob(nums));
    }

    return 0;
}

int rob(vector<int>& nums) {
    int rob = 0, not_rob = 0;
    for (int i = 0; i < nums.size(); i++){
        int prev = max(rob, not_rob);
        rob = not_rob + nums[i];
        not_rob = prev;
    }

    return max(rob, not_rob);
}
