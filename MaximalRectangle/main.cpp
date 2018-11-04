#include <iostream>
#include <vector>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix);

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
	if (matrix.empty())
		return 0;

	struct Cord {
		int x, y;
		Cord(): x(-1), y(-1) {}
	};

	auto table = new Cord*[matrix.size()];
	for (int i = 0; i < matrix.size(); ++i)
		table[i] = new Cord[matrix[i].size()];

	int area = 0;
	if (matrix[0][0] == '1') {
		table[0][0].x = table[0][0].y = 0;
		area = 1;
	}
	for (int j = 1; j < matrix[0].size(); ++j) {
		if(matrix[0][j] == '0')
			continue;

		table[0][j].x = 0;
		table[0][j].y = (matrix[0][j - 1] == '0')? j : table[0][j - 1].y;
		area = max(area, j - table[0][j].y + 1);
	}
	for (int i = 1; i < matrix.size(); ++i) {
		if (matrix[i][0] == '0')
			continue;

		table[i][0].x = (matrix[i - 1][0] == '0')? i : table[i - 1][0].y;
		table[i][0].y = 0;
		area = max(area, i - table[i][0].x + 1);
	}


	for (int i = 1; i < matrix.size(); ++i) {
		for (int j = 1; j < matrix[i].size(); ++j) {
			if (matrix[i][j] == '0')
				continue;
			if (matrix[i][j - 1] == '1' and matrix[i - 1][j] == '1') {
				// TODO: induction to do
			} else if (matrix[i][j - 1] == '1') {
				table[i][j].x = i;
				table[i][j].y = table[i][j - 1].y;
			} else if (matrix[i - 1][j] == '1') {
				table[i][j].x = table[i - 1][j].x;
				table[i][j].y = j;
			} else {
				table[i][j].x = i;
				table[i][j].y = j;
			}
			area = max(area, (i - table[i][j].x + 1)*(j - table[i][j].y + 1));
		}
	}
	return area;
}