#include <vector>
#include <iostream>

using namespace std;

int solution(int N, int K);

int main(){
    vector<vector<int>> N = {{18, 2}, {8, 0}, {10, 10}};    //6, 7, 4
    for (vector<int> N_K : N){
        printf("%d", solution(N_K[0], N_K[1]));
    }

    return 0;
}

int solution(int N, int K){
    int round = 0;
    while (N > 1){
        if (N % 2 != 0 || K == 0){
            N --;
        }else if (N / 2 > 0 && N % 2 == 0 && K > 0){
            N /= 2;
            K --;
        }
        round ++;
    }
    return round;
}
