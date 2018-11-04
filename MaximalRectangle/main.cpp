#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix);
int largestRectangleArea(vector<int> heights);

int main() {
	int row, col;
	cin >> row >> col;
	vector<vector<char>> matrix;
	for (int i = 0; i < row; ++i) {
		vector<char> line;
		char ch;
		for (int j = 0; j < col; ++j) {
			cin >> ch;
			line.emplace_back(ch);
		}
		matrix.emplace_back(line);
	}
	cout << maximalRectangle(matrix) << endl;
	return 0;
}

int maximalRectangle(vector<vector<char>>& matrix) {
	if (matrix.empty() or matrix[0].empty())
		return 0;
	int area = 0;
	vector<vector<int>> heights;

	vector<int> line(matrix[0].size());
	for (int i = 0; i < line.size(); ++i)
		line[i] = matrix[0][i] == '1'? 1 : 0;
	heights.emplace_back(line);
	for (int i = 1; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[i].size(); ++j) {
			if (matrix[i][j] == '0')
				line[j] = 0;
			else
				line[j] = heights[i - 1][j] + 1;
		}
		heights.emplace_back(line);
	}
	for (int i = 0; i < matrix.size(); ++i)
		area = max(area, largestRectangleArea(heights[i]));
	return area;
}

int largestRectangleArea(vector<int> heights) {
	if (heights.empty())
		return 0;
	if (heights.size() == 1)
		return heights[0];

	heights.emplace_back(0);
	stack<int> bound;
	int ret = 0;
	for (int i = 0; i < heights.size(); ++i) {
		while (not bound.empty() and heights[i] < heights[bound.top()]) {
			int lower = heights[bound.top()];
			bound.pop();
			int length = bound.empty()? i : i - bound.top() - 1;
			ret = max(ret, length*lower);
		}
		bound.push(i);
	}
	return ret;
}