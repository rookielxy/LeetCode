#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int swimInWater(const vector<vector<int>>& grid);
bool reachable(const vector<vector<int>>& grid, int time);
inline bool isValid(int x, int y, size_t N);

int main() {
	size_t N;
	cin >> N;
	vector<vector<int>> grid(N);
	for (vector<int> &array : grid) {
		array.resize(N);
		for (int &ele : array)
			cin >> ele;
	}
	cout << swimInWater(grid) << endl;
	return 0;
}

int swimInWater(const vector<vector<int>>& grid) {
	if (grid.empty() or grid[0].empty())
		return 0;
	if (grid.size() == 1 and grid[0].size() == 1)
		return 0;
	int N = (int)grid.size(), begin = max(grid[0][0], grid[N - 1][N - 1]),
		end = N*N - 1, middle = begin + (end - begin)/2;
	if (reachable(grid, begin))
		return begin;
	while (begin != middle) {
		if (reachable(grid, middle))
			end = middle;
		else
			begin = middle;
		middle = begin + (end - begin)/2;
	}
	return end;
}

bool reachable(const vector<vector<int>>& grid, int time) {
	queue<pair<int, int>> locations;
	vector<vector<bool>> visited(grid.size());
	for (vector<bool> &array : visited)
		array.resize(grid.size());
	locations.emplace(0, 0);
	while (not locations.empty()) {
		int x = locations.front().first, y = locations.front().second;
		if (x == grid.size() - 1 and y == grid.size() - 1)
			return true;
		if (isValid(x + 1, y, grid.size()) and grid[x + 1][y] <= time and not visited[x + 1][y]) {
			locations.emplace(x + 1, y);
			visited[x + 1][y] = true;
		}
		if (isValid(x, y + 1, grid.size()) and grid[x][y + 1] <= time and not visited[x][y + 1]) {
			locations.emplace(x, y + 1);
			visited[x][y + 1] = true;
		}
		if (isValid(x - 1, y, grid.size()) and grid[x - 1][y] <= time and not visited[x - 1][y]) {
			locations.emplace(x - 1, y);
			visited[x - 1][y] = true;
		}
		if (isValid(x, y - 1, grid.size()) and grid[x][y - 1] <= time and not visited[x][y - 1]) {
			locations.emplace(x, y - 1);
			visited[x][y - 1] = true;
		}
		locations.pop();
	}
	return false;
}

inline bool isValid(int x, int y, size_t N) {
	return x >= 0 and x < N and y >= 0 and y < N;
}