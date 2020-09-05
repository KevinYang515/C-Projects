#include <iostream>
#include <vector>

using namespace std;

int findDuplicate_1(vector<int>& nums);
int findDuplicate_2(vector<int>& nums);

int main(){
    vector<vector<int>> nums_v = {{1,3,4,2,2}, {3,1,3,4,2}, {1,1}, {1,1,2}};
    // 2, 3, 1, 1
    for (vector<int> nums : nums_v){
        printf("%d, ",findDuplicate_1(nums));
    }
    printf("\n=================================\n");
    for (vector<int> nums : nums_v){
        printf("%d, ",findDuplicate_2(nums));
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
int findDuplicate_1(vector<int>& nums) {
    for (int i = 0;  i < nums.size(); i++){
        if (nums[abs(nums[i])] < 0) return abs(nums[i]);
        nums[abs(nums[i])] *= -1;
    }
    return -1;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
// without modifying the array nums 
int findDuplicate_2(vector<int>& nums) {
    if (nums.size() == 2) return nums[0];
        int tortoise = nums[0], hare = nums[0];
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }while (tortoise != hare);
        hare = nums[0];
        while (tortoise != hare){
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return hare;
}
