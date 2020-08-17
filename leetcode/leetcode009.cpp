#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<int> x_v = {121, -121, 10};
    for (int x : x_v){
        printf("%s \n", isPalindrome(x) ? "true" : "false");
    }
    
    return 0;
}

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)){
        return false;
    }
    int invert_val = 0;
    while (x > invert_val){
        invert_val = invert_val * 10 + x % 10;
        x /= 10;
    }

    return x == invert_val || x == invert_val / 10;
}
