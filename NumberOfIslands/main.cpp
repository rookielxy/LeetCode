#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j);
int numIslands(vector<vector<char>>& grid);

int main() {
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}};
    cout << numIslands(grid) << endl;
    return 0;
}

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
    visited[i][j] = true;
    if (i + 1 < grid.size() and grid[i + 1][j] == '1' and not visited[i + 1][j])
        dfs(grid, visited, i + 1, j);
    if (j + 1 < grid[i].size() and grid[i][j + 1] == '1' and not visited[i][j + 1])
        dfs(grid, visited, i, j + 1);
    if (i - 1 >= 0 and grid[i - 1][j] == '1' and not visited[i - 1][j])
        dfs(grid, visited, i - 1, j);
    if (j - 1 >= 0 and grid[i][j - 1] == '1' and not visited[i][j - 1])
        dfs(grid, visited, i, j - 1);
}

int numIslands(vector<vector<char>>& grid) {
    assert(not grid.empty());
    assert(not grid[0].empty());

    int row = grid.size(), col = grid[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    int nIslands = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == '0' or visited[i][j])
                continue;
            ++nIslands;
            dfs(grid, visited, i, j);
        }
    }
    return nIslands;
}
