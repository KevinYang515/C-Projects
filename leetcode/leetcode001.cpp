#include <vector>
#include <stdio.h>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    for (int x : twoSum(nums, target)){
        printf("%d, ", x);
    }

    return 0;
}

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> num_map;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++){
        if (num_map.find(target - nums[i]) != num_map.end()){
            result.push_back(num_map[target - nums[i]]);
            result.push_back(i);
            return result;
        }
        num_map[nums[i]] = i;
    }
    return result;
}