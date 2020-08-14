#include <iostream>
#include <string>

using namespace std;

int main() {
    int n = 10; 
    int *p  = nullptr;
    p = &n;

    cout << "n: " << &n << endl
         << "p: " << p << endl
         << "p: " << *p << endl;

    *p = 20;

    cout << "n: " << n << endl
         << "p: " << p << endl
         << "p: " << *p << endl;

    // system("pause");
    return 0;
}