#include <vector>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> mostVisited_1(int n, vector<int>& rounds);
vector<int> mostVisited_2(int n, vector<int>& rounds);

int main(){
    vector<int> n_v ={4, 2, 7, 3};
    vector<vector<int>> rounds_v = {{1,3,1,2}, 
                                    {2,1,2,1,2,1,2,1,2}, 
                                    {1,3,5,7},
                                    {3,2,1,2,1,3,2,1,2,1,3,2,3,1}};

    for (int i = 0; i < n_v.size(); i++){
        for (int ans : mostVisited_1(n_v[i], rounds_v[i])){
            printf("%d, ", ans);
        }
        printf("\n");
    }

    printf("==================\n");

    for (int i = 0; i < n_v.size(); i++){
        for (int ans : mostVisited_2(n_v[i], rounds_v[i])){
            printf("%d, ", ans);
        }
        printf("\n");
    }

    return 0;
}

vector<int> mostVisited_1(int n, vector<int>& rounds) {
    map<int, int> count;
    vector<int> result;
    for (int i = 0; i < n; i++){
        count[i + 1] = 0; 
    }

    for (int i = 0; i < rounds.size() - 1; i++){
        int start = rounds[i];
        int end = rounds[i + 1];
        if(i == 0) count[start] += 1;
        while (start != end){
            start ++;
            start %= n;
            if (start == 0) start = n;
            count[start] += 1;
        }
    }

    int max = count[rounds[0]];

    for(map<int,int>::iterator it = count.begin(); it != count.end(); ++it) {
        if (it->second == max){
            result.push_back(it->first);
        }
    }

    return result;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> mostVisited_2(int n, vector<int>& rounds){
    vector<int> result;
    for (int i = rounds[0]; i <= rounds[rounds.size() - 1]; i++){
        result.push_back(i);
    }
    if (result.size() > 0) return result;
    for (int i = 1; i <= rounds[rounds.size() - 1]; i++)
        result.push_back(i);
    for (int i = rounds[0]; i <= n; i++)
        result.push_back(i);
        
    return result;
}
