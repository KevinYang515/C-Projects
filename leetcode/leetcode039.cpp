#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target);
void combinationSum(vector<int>& candidates, int target, int sum, int m, 
                    vector<int>& current, vector<vector<int>>& result);

int main(){
    vector<vector<int>> candidates_v = {{2,3,6,7}, {2,3,5}};
    vector<int> target_v = {7, 8};

    for (int i =0; i < candidates_v.size(); i++){
        for (vector<int> answer : combinationSum(candidates_v[i], target_v[i])){
            for (int ans : answer){
                printf("%d, ", ans);
            }
            printf("\n");
        }
        printf("=========================\n");
    }

    return 0;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> current;
    vector<vector<int>> result;
    combinationSum(candidates, target, 0, 0, current, result);
    return result;
}

void combinationSum(vector<int>& candidates, int target, int sum, int start, vector<int>& current, vector<vector<int>>& result){
    if (sum == target){
        result.push_back(current);
    }else if (sum < target){
        for (int i = start; i < candidates.size(); i++){
            current.push_back(candidates[i]);
            combinationSum(candidates, target, sum + candidates[i], i, current, result);
            current.erase(current.end() - 1);
        }
    }
}
