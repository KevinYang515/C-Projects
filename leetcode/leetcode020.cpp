#include <vector>
#include <string>
#include <map>
#include <stack>
#include <iostream>

using namespace std;

bool isValid_1(string s);
bool isValid_2(string s);

int main(){
    vector<string> s_v = {"()", "()[]{}", "(]", "[", "]"};

    for (string s : s_v){
        printf("%s \n", isValid_1(s) ? "true":"false");
    }
    printf("\n");
    for (string s : s_v){
        printf("%s \n", isValid_2(s) ? "true":"false");
    }

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
bool isValid_1(string s) {
    map<char, char> mappings;
    stack<char> stac;

    mappings['}'] = '{';
    mappings[']'] = '[';
    mappings[')'] = '(';

    for (char &c : s){
        if (mappings.find(c) != mappings.end()){
            char temp = stac.empty() ? '#' : stac.top();
            stac.pop();
            if (temp != mappings[c]){
                return false;
            }
        }else {
            stac.push(c);
        }
    }

    return stac.empty();
}

// Time Complexity: O(n)
// Space Complexity: O(n)
bool isValid_2(string s) {
    stack<char> stac;
    for (char &c : s){
        if (c == '{'){
            stac.push('}');
        }else if (c == '['){
            stac.push(']');
        }else if (c == '('){
            stac.push(')');
        }else if (!stac.empty() && stac.top() == c){
            stac.pop();
        }else if (stac.empty() || stac.top() != c){
            return false;
        }
    }
    return stac.empty();
}
