#include<iostream>
#include<vector>

using namespace std;

int climbStairs(int n);

int main(){
    vector<int> n_v = {2, 3};
    for (int n : n_v){
        printf("%d \n", climbStairs(n));
    }
}

// Time Complexity: O(n)
// Space Complexity: O(n)
int climbStairs(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
