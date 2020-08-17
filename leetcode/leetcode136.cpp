#include <vector>
#include <iostream>
#include <map>

using namespace std;

int singleNumber_1(vector<int>& nums);
int singleNumber_2(vector<int>& nums);

int main(){
    vector<vector<int>> nums_v = {{2, 2, 1}, {4, 1, 2, 1, 2}};
    for (vector<int> nums : nums_v){
        printf("%d, ", singleNumber_1(nums));
    }
    printf("\n");
    for (vector<int> nums : nums_v){
        printf("%d, ", singleNumber_2(nums));
    }

    return 0;
}

int singleNumber_1(vector<int>& nums) {
    map<int, int> nums_map;
    for (int num : nums){
        if (nums_map.find(num) != nums_map.end()){
            nums_map[num] += 1;
        }else {
            nums_map[num] = 1;
        }
    }

    vector<int> v;
    for(map<int,int>::iterator it = nums_map.begin(); it != nums_map.end(); it++) {
        if (it->second != 2){
            return it->first;
        }
    }

    return 0;
}

int singleNumber_2(vector<int>& nums) {
    int a = 0;
    for (int num : nums){
        a ^= num;
    }
    return a;
}
