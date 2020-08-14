#include <vector>
#include <climits>
#include <stdio.h>
#include <iostream>

using namespace std;

int mincostTickets(vector<int>& days, vector<int>& costs);

int main(){
    vector<vector<int>> days = {{1,4,6,7,8,20}, {1,2,3,4,5,6,7,8,9,10,30,31}};
    vector<vector<int>> costs = {{2,7,15}, {2,7,15}};

    printf("%d \n", mincostTickets(days.at(0), costs.at(0)));
    printf("%d \n", mincostTickets(days.at(1), costs[1]));

    return 0;
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp(365, INT_MAX);
    for (int day : days){
        dp[day] = 0;
    }
    dp[0] = 0;
    for (int i = 1; i < days[days.size() - 1] + 1; i++){
        if (dp[i] == INT_MAX){
            dp[i] = dp[i - 1];
        }else {
            int current = dp[i - 1] + costs[0];
            current = min(current, costs[1] + dp[max(0, i - 7)]);
            current = min(current, costs[2] + dp[max(0, i - 30)]);
            dp[i] = current;
        }
    }
    return dp[days[days.size() - 1]];
}