#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s);
int main() {
    vector<string> s = {"abcabcbb", "bbbbb"};
    string s1[2] = {"abcabcbb", "bbbbb"};

    for (string s_temp : s){
        printf("%d, ", lengthOfLongestSubstring(s_temp));
    }

    return 0;
}

int lengthOfLongestSubstring(string s) {
    const char* str = s.c_str();
    int ans = 0;
    map<char, int> my_map;
    for (int i = 0, j = 0; j < s.length(); j ++){
        if (my_map.find(str[j]) != my_map.end()){
            i = max(i, my_map.find(str[j])->second);
            // i = max(i, my_map[str[j]]);
        }
        ans = max(ans, j - i + 1);
        my_map[str[j]] = j + 1;
    }

    return ans;
}