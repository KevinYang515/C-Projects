#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf_1(vector<int>& nums);
vector<int> productExceptSelf_2(vector<int>& nums);
vector<int> productExceptSelf_3(vector<int>& nums);

int main(){
    vector<vector<int>> nums_v = {{1,2,3,4}, {4,5,1,8,2}};
    for (vector<int> nums : nums_v){
        for (int ans : productExceptSelf_1(nums)){
            printf("%d, ", ans);
        }
        printf("\n");
    }
    printf("===========================\n");
    for (vector<int> nums : nums_v){
        for (int ans : productExceptSelf_2(nums)){
            printf("%d, ", ans);
        }
        printf("\n");
    }
    printf("===========================\n");
    for (vector<int> nums : nums_v){
        for (int ans : productExceptSelf_3(nums)){
            printf("%d, ", ans);
        }
        printf("\n");
    }

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> productExceptSelf_1(vector<int>& nums){
    vector<int> left(nums.size(), 0);
    vector<int> right(nums.size(), 0);
    vector<int> result(nums.size(), 0);
    int temp = 1;
    for (int i = 0; i < nums.size(); i++){
        left[i] = temp; 
        temp *= nums[i];
    }

    temp = 1;
    for (int i = nums.size() - 1; i >= 0; i--){
        right[i] = temp;
        temp *= nums[i];
    }

    for (int i = 0; i < nums.size(); i++){
        result[i] = left[i] * right[i];
    }

    return result;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> productExceptSelf_2(vector<int>& nums){
    vector<int> right(nums.size(), 0);
    vector<int> result(nums.size(), 0);
    int temp = 1;
    for (int i = 0; i < nums.size(); i++){
        result[i] = temp;
        temp *= nums[i];
    }

    temp = 1;
    for (int i = nums.size() - 1; i >= 0; i--){
        right[i] = temp;
        temp *= nums[i];
    }

    for (int i = 0; i < nums.size(); i++){
        result[i] = result[i] * right[i];
    }

    return result;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
vector<int> productExceptSelf_3(vector<int>& nums) {
    int right = 1;
    vector<int> result(nums.size(), 0);
    
    int temp = 1;
    for (int i = 0; i < nums.size(); i++){
        result[i] = temp;
        temp *= nums[i];
    }

    for (int i = nums.size() - 1; i >= 0; i--){
        result[i] *= right;
        right *= nums[i];
    }
    
    return result;
}
