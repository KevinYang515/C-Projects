#include <iostream>
#include <vector>

using namespace std;

bool isPowerOfThree(int n);

int main(){
    vector<int> n_v = {27, 0, 9, 45};
    for (int n : n_v){
        printf("%s, ", isPowerOfThree(n) ? "true" : "false");
    }

    return 0;
}

bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    while (n % 3 == 0){
        n /= 3;
    }
    
    return n == 1;
}
