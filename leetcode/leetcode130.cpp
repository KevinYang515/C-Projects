#include <iostream>
#include <vector>

using namespace std;

void solve(vector<vector<char>>& board);
void dfs(int i, int j, vector<vector<char>> &board);

int main(){
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};
    solve(board);
    for (vector<char> answer : board){
        printf("[");
        for (char ans: answer){
            printf("%c, ", ans);
        }
        printf("]\n");
    }
    return 0;
}

int length = 0, width = 0;

void solve(vector<vector<char>>& board) {
    if (board.size() == 0) return;
    length = board.size();
    width = board[0].size();
    for (int i = 0; i < length; i++){
        if (board[i][0] == 'O') dfs(i, 0, board);
        if (board[i][width - 1] == 'O') dfs(i, width - 1, board);
    }
    for (int i = 0; i < width; i++){
        if (board[0][i] == 'O') dfs(0, i, board);
        if (board[length - 1][i] == 'O') dfs(length - 1, i, board);
    }
    for (int i = 0; i < length; i++){
        for (int j = 0; j < width; j++){
            if (board[i][j] == 'O') board[i][j] = 'X';
            if (board[i][j] == 'Z') board[i][j] = 'O';
        }
    }
}

void dfs(int i, int j, vector<vector<char>> &board){
    if (i < 0 || i >= length || j < 0 || j >= width || board[i][j] != 'O') return;

    board[i][j] = 'Z';

    dfs(i + 1, j, board);
    dfs(i - 1, j, board);
    dfs(i, j + 1, board);
    dfs(i, j - 1, board);
}
