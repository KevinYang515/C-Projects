#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites);

int main(){
    vector<int> numCourses_v = {2, 2};
    vector<vector<vector<int>>> prerequisites_v = {{{1, 0}}, {{1, 0}, {0, 1}}};
    // True, False
    for (int i = 0; i < numCourses_v.size(); i++){
        printf("%s, ", canFinish(numCourses_v[i], prerequisites_v[i]) ? "True" : "False");
    }

    return 0;
}

// Time Complexity: O(n)
// Space Complextiy: O(n)
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    queue<int> q;
    map<int, vector<int>> schedule;
    vector<int> indegree(numCourses, 0);
    for (vector<int> prerequire : prerequisites){
        indegree[prerequire[0]] ++;
        if (schedule.find(prerequire[1]) != schedule.end()){
            schedule[prerequire[1]].push_back(prerequire[0]);
        }else {
            schedule[prerequire[1]] = vector<int> {prerequire[0]};
        }
    }   

    for (int i = 0; i < numCourses; i++){
        if (indegree[i] == 0) q.push(i);
    }
    while (!q.empty()){
        int course = q.front();
        q.pop();
        vector<int> current = schedule[course];
        for (int c : current){
            indegree[c] --;
            if (indegree[c] == 0) q.push(c);
        }
    }
    for (int i = 0; i < numCourses; i++){
        if (indegree[i] > 0) return false;
    }
    return true;
}
