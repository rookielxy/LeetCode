#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix);

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> matrix((unsigned)m);
	for (int i = 0; i < m; ++i) {
		int data;
		for (int j = 0; j < n; ++j) {
			cin >> data;
			matrix[i].emplace_back(data);
		}
	}
	for (auto &ele : spiralOrder(matrix))
		cout << ele << endl;
	return 0;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> ret;
	if (matrix.empty() or matrix[0].empty())
		return ret;
	ret.insert(ret.begin(), matrix[0].begin(), matrix[0].end());
	matrix.erase(matrix.begin());
	if (matrix.empty())
		return ret;
	for (int i = 0; i < matrix.size() - 1; ++i) {
		ret.emplace_back(matrix[i].back());
		matrix[i].pop_back();
	}
	reverse(matrix.back().begin(), matrix.back().end());
	ret.insert(ret.end(), matrix.back().begin(), matrix.back().end());
	matrix.pop_back();
	for (int i = (int)matrix.size() - 1; i >= 0 ; --i) {
		if (matrix[i].empty())
			return ret;
		ret.emplace_back(matrix[i][0]);
		matrix[i].erase(matrix[i].begin());
	}
	vector<int> rest = spiralOrder(matrix);
	ret.insert(ret.end(), rest.begin(), rest.end());
	return ret;
}