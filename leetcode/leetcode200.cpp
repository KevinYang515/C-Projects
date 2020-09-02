#include <iostream>
#include <vector>

using namespace std;

int numIslands(vector<vector<char>>& grid);
void numIslands(int i, int j);

int main(){
    vector<vector<vector<char>>> grid_v = {{{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}}, 
                                          {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}}};
    // 1, 3
    for (vector<vector<char>> gird : grid_v){
        printf("%d, ", numIslands(gird));
    }

    return 0;
}

int length = 0, width = 0;
vector<vector<char>> island;

// Time Complexity: O(n)
// Space Complexity: O(n)
int numIslands(vector<vector<char>>& grid) {
    if (grid.size() == 0) return 0;
    int region = 0;
    length = grid.size();
    width = grid[0].size();
    island = grid;
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[0].size(); j++){
            if (island[i][j] == '1'){
                numIslands(i, j);
                region ++;
            }
        }
    }
    return region;
}

void numIslands(int i, int j){
    if (i >= length || i < 0 || j >= width || j < 0 || island[i][j] != '1') return;
    
    island[i][j] = '0';

    numIslands(i + 1, j);
    numIslands(i - 1, j);
    numIslands(i, j + 1);
    numIslands(i, j - 1);
}
