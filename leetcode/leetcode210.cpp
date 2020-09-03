#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> findOrder_1(int numCourses, vector<vector<int>>& prerequisites);
vector<int> findOrder_2(int numCourses, vector<vector<int>>& prerequisites);

int main(){
    vector<int> numCourses_v = {2, 4, 1, 3};
    vector<vector<vector<int>>> prerequisites_v = {{{1,0}}, 
                                                   {{1,0},{2,0},{3,1}},
                                                   {},
                                                   {{1,0},{1,2},{0,1}}};
    // [0,1], [0,2,1,3], [0], []
    for (int i = 0; i < numCourses_v.size(); i++){
        for (int ans: findOrder_1(numCourses_v[i], prerequisites_v[i])){
            printf("%d, ", ans);
        }
        printf("\n");
    }
    printf("==========================================\n");
    for (int i = 0; i < numCourses_v.size(); i++){
        for (int ans: findOrder_2(numCourses_v[i], prerequisites_v[i])){
            printf("%d, ", ans);
        }
        printf("\n");
    }

    return 0;
}

vector<int> findOrder_1(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> result;
    vector<int> indegree(numCourses, 0);
    map<int, vector<int>> schedule;
    for (vector<int> prerequire : prerequisites){
        indegree[prerequire[0]] ++;
        if (schedule.find(prerequire[1]) != schedule.end()){
            schedule[prerequire[1]].push_back(prerequire[0]);
        }else {
            schedule[prerequire[1]] = vector<int> {prerequire[0]};
        }
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++){
        if (indegree[i] == 0) {
            q.push(i);
            result.push_back(i);
        }
    }

    while (!q.empty()){
        int course = q.front();
        q.pop();
        for (int c : schedule[course]){
            indegree[c] --;
            if (indegree[c] == 0) {
                q.push(c);
                result.push_back(c);
            }
        }
    }
    for (int i = 0; i < numCourses; i++){
        if (indegree[i] != 0) return vector<int>{};
    }
    return result;
}


vector<int> findOrder_2(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> result(numCourses, 0);
    vector<int> indegree(numCourses, 0);
    map<int, vector<int>> schedule;
    for (vector<int> prerequire : prerequisites){
        indegree[prerequire[0]] ++;
        if (schedule.find(prerequire[1]) != schedule.end()){
            schedule[prerequire[1]].push_back(prerequire[0]);
        }else {
            schedule[prerequire[1]] = vector<int> {prerequire[0]};
        }
    }
    int first = 0, last = 0;
    for (int i = 0; i < numCourses; i++){
        if (indegree[i] == 0) {
            result[last] = i;
            last ++;
        }
    }

    while (first < last){
        for (int c : schedule[result[first]]){
            indegree[c] --;
            if (indegree[c] == 0) {
                result[last] = c;
                last ++;
            }
        }
        first ++;
    }
    if (last != numCourses) return vector<int>{};

    return result;
}
