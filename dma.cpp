#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
    // statically obtain an integer
    int x; 

    // dynamically obtain an integer
    int *px = (int*)malloc(sizeof(int));

    return 0;
}