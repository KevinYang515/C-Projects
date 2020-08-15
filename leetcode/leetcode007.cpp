#include <iostream>
#include <vector>

using namespace std;

int reverse(int x);

int main(){
    vector<int> x_v = {123, -123, 120};

    for (int x : x_v){
        printf("%d \n", reverse(x));
    }

    return 0;
}

int reverse(int x) {
    long result = 0;
    while (x != 0){
        result = result * 10 + x % 10;
        x /= 10;
    }

    if (result < INT_MIN || result > INT_MAX){
        return 0;
    }else {
        return (int)result;
    }
}
