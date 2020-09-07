#include<iostream>
#include<vector>
#include<math.h>
#include<queue>

using namespace std;

int numSquares_1(int n);
int numSquares_2(int n);

int main(){
    vector<int> n_v = {12, 13, 1, 2};
    // 3, 2, 1, 2
    for (int n : n_v){
        printf("%d, ", numSquares_1(n));
    }
    return 0;
}

// BFS

int numSquares_1(int n) {
    int steps = 1, bound = sqrt(n);
    queue<int> tocheck;
    tocheck.push(0);
    while (!tocheck.empty()){
        int size = tocheck.size();
        for (int i = 0; i < size; i++){
            int current = tocheck.front();
            tocheck.pop();
            for (int j = 1; j <= bound; j++){
                int sum = current + j * j;
                if (sum == n) return steps;
                else if (sum < n) tocheck.push(sum);
            }
        }
        steps ++;
    }
    return steps;
}

int numSquares_2(int n) {
    int dp[n + 1];
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = INT_MAX;
        for (int j = 1; j * j <= i; j++){
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }
    return dp[n];
}
