#include <iostream>
#include <vector>

using namespace std;

int orangesRotting(vector<vector<int>>& grid);
void dfs(vector<vector<int>>& grid, int row, int col, int time);
void tryDFS(vector<vector<int>>& grid, int row, int col, int time);

int main() {
	int row, col;
	vector<vector<int>> input;
	cin >> row >> col;
	for (int i = 0; i < row; ++i) {
		vector<int> temp;
		for (int j = 0; j < col; ++j) {
			int data;
			cin >> data;
			temp.emplace_back(data);
		}
		input.emplace_back(temp);
	}
	cout << orangesRotting(input) << endl;
	return 0;
}

vector<vector<int>> dis;
int orangesRotting(vector<vector<int>>& grid) {
    if (grid.empty() or grid[0].empty())
        return 0;
    dis.resize(grid.size());
    for (int i = 0; i < dis.size(); ++i) {
        dis[i].resize(grid[i].size());
        for (int &ele : dis[i])
            ele = 2147483647;
    }
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == 2) {
                dis[i][j] = 0;
            }
        }
    }
	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[i].size(); ++j) {
			if (grid[i][j] == 2) {
				dfs(grid, i, j, 0);
			}
		}
	}
    int maxi = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] != 0 and dis[i][j] > maxi)
                maxi = dis[i][j];
        }
    }
    return (maxi == 2147483647)? -1 : maxi;
}

void tryDFS(vector<vector<int>>& grid, int row, int col, int time) {
    if (row >=0 and row < grid.size() and col >= 0 and col < grid[row].size()) {
        if (grid[row][col] != 0 and dis[row][col] > time) {
            dis[row][col] = time;
            dfs(grid, row, col, time);
        }
    }
}

void dfs(vector<vector<int>>& grid, int row, int col, int time) {
    tryDFS(grid, row - 1, col, time + 1);
    tryDFS(grid, row, col + 1, time + 1);
    tryDFS(grid, row + 1, col, time + 1);
    tryDFS(grid, row, col - 1, time + 1);
}