#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

#define DIMENSION 9

bool checkValid(int i, int j, int num);
void fillIn(int i, int j, int num, vector<vector<char>>& board);
void wrapOut(int i, int j, int num, vector<vector<char>>& board);
void initState(vector<vector<char>>& board);
bool DFS(int i, int j, vector<vector<char>>& board);
void solveSudoku(vector<vector<char>>& board);

bool row[9][9];
bool col[9][9];
bool square[9][9];

int main() {
    vector<vector<char>> board;
    board.resize(DIMENSION);
    for(int i = 0; i < DIMENSION; ++i) {
        board[i].resize(DIMENSION);
        for(int j = 0; j < DIMENSION; ++j)
            cin >> board[i][j];
    }
    solveSudoku(board);
    for(const auto& r: board) {
        for(auto c: r)
            cout << c << " ";
        cout << endl;
    }
    return 0;
}

bool checkValid(int i, int j, int num) {
    int squareIdx = i - i%3 + j/3;
    return row[i][num - 1] and col[j][num - 1] and square[squareIdx][num - 1];
}

void fillIn(int i, int j, int num, vector<vector<char>>& board) {
    int squareIdx = i - i%3 + j/3;
    row[i][num - 1] = false;
    col[j][num - 1] = false;
    square[squareIdx][num - 1] = false;
    char ch = (char)('0' + num);
    board[i][j] = ch;
}

void wrapOut(int i, int j, int num, vector<vector<char>>& board) {
    int squareIdx = i - i%3 + j/3;
    row[i][num - 1] = true;
    col[j][num - 1] = true;
    square[squareIdx][num - 1] = true;
    board[i][j] = '.';
}

void initState(vector<vector<char>>& board) {
    for(int i = 0; i < DIMENSION; ++i) {
        memset(row[i], true, DIMENSION);
        memset(col[i], true, DIMENSION);
        memset(square[i], true, DIMENSION);
    }
    for(int i = 0; i < DIMENSION; ++i) {
        for(int j = 0; j < DIMENSION; ++j) {
            if(board[i][j] == '.')
                continue;
            else {
                int num = board[i][j] - '0';
                fillIn(i, j, num, board);
            }
        }
    }
}

bool DFS(int i, int j, vector<vector<char>>& board) {
    vector<int> valid;
    for(int k = 1; k <= DIMENSION; ++k)
        if(checkValid(i, j, k))
            valid.push_back(k);
    if(valid.empty())
        return false;

    int nextRow, nextCol;
    nextRow = (j == DIMENSION - 1)? i + 1: i;
    nextCol = (j == DIMENSION - 1)? 0: j + 1;
    for(; nextRow < DIMENSION; nextRow += (nextCol + 1)/DIMENSION,
            nextCol = (nextCol + 1)%DIMENSION)
        if(board[nextRow][nextCol] == '.')
            break;
    if(nextRow == DIMENSION) {
        fillIn(i, j, valid.front(), board);
        return true;
    }

    for(auto ele: valid) {
        fillIn(i, j, ele, board);
        if(DFS(nextRow, nextCol, board))
            return true;
        else
            wrapOut(i, j, ele, board);
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    initState(board);
    for(int i = 0; i < DIMENSION; ++i) {
        for(int j = 0; j < DIMENSION; ++j) {
            if(board[i][j] != '.')
                continue;
            else
                assert(DFS(i, j, board));
        }
    }
}
