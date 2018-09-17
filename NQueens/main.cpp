#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

//vector<vector<string>> solveNQueens(int n);
int solutionChain(int n);
int totalNQueens(int n);
void deepFirst(int n, vector<int> &path, int &count);

int main() {
    int d;
    cin >> d;
    cout << totalNQueens(d) << endl;
    return 0;
}

int totalNQueens(int n) {
    int count = 0;
    vector<int> path;
    deepFirst(n, path, count);
    return count;
}

/*
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solution;
    vector<vector<int>> chain = solutionChain(n);
    for(auto const &ele: chain) {
        vector<string> board;
        for(auto row: ele) {
            string str;
            for(int i = 0; i < row; ++i)
                str += '.';
            str += 'Q';
            for(int i = row + 1; i < n; ++i)
                str += '.';
            board.push_back(str);
        }
        solution.push_back(board);
    }
    return solution;
}
*/


void deepFirst(int n, vector<int> &path, int &count) {
    if(path.size() == n) {
        ++count;
        return;
    }
    auto avail = new bool[n];
    memset(avail, true, (size_t)n);
    for(int i = 0; i < path.size(); ++i) {
        int offset = (int)path.size() - i;
        avail[path[i]] = false;
        if(path[i] + offset >= 0 and path[i] + offset < n)
            avail[path[i] + offset] = false;
        if(path[i] - offset >= 0 and path[i] - offset < n)
            avail[path[i] - offset] = false;
    }

    path.push_back(-1);
    for(int i = 0; i < n; ++i) {
        if(avail[i]) {
            path.back() = i;
            deepFirst(n, path, count);
        }
    }
    path.pop_back();
}