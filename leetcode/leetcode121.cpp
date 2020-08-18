#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices);

int main(){
    vector<vector<int>> prices_v = {{7,1,5,3,6,4}, {7,6,4,3,1}};
    for (vector<int> prices : prices_v){
        printf("%d, ", maxProfit(prices));
    }

    return 0;
}

int maxProfit(vector<int>& prices) {
    if (prices.size() == 0 || prices.size() == 1) return 0;
    int buy = prices[0], maxprofit = 0;
    for (int i = 1; i < prices.size(); i++){
        if (prices[i] < buy) buy = prices[i];
        if (prices[i] - buy > maxprofit) maxprofit = prices[i] - buy;
    }

    return maxprofit;
}
