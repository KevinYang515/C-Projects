#include <iostream>
#include <vector>

using namespace std;

int numDecodings(string s);
int helper(string s, int k, vector<int>& dp);

int main(){
    vector<string> s_v = {"12", "226", "0"};
    // 2, 3, 0
    for (string s : s_v){
        printf("%d, ", numDecodings(s));
    }
    return 0;
}

int numDecodings(string s) {
    vector<int> dp(s.size() + 1, -1);
    return helper(s, s.size(), dp);
}

int helper(string s, int k, vector<int>& dp){
    if (k == 0) {
        dp[k] = 1;
        return 1;
    }
    int pos = s.size() - k, cur = s[pos] - '0';
    if (cur == 0) return 0;
    if (dp[k] != -1) return dp[k];
    int result = helper(s, k - 1, dp);
    if (k > 1){
        int sum = cur * 10 + (int)(s[pos + 1] - '0');
        if (sum <= 26)
            result += helper(s, k - 2, dp);
    }
    dp[k] = result;
    return result;
}
