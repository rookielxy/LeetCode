#include <iostream>
#include <vector>

using namespace std;

enum Direction { LEFT, RIGHT, UP, DOWN };;

vector<vector<int>> generateMatrix(int n);
void nextStep(int& row, int& col, int n, enum Direction& direct);

int main() {
	int n;
	cin >> n;
	vector<vector<int>> matrix = generateMatrix(n);
	for (vector<int> &array : matrix) {
		for (int ele : array)
			cout << ele << " ";
		cout << endl;
	}
	return 0;
}

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> matrix((unsigned)n);
	for (vector<int> &array : matrix)
		array.resize((unsigned)n);
	int row = 0, col = 0;
	enum Direction direct = LEFT;
	for (int content = 1; content <= n*n; ++content) {
		matrix[row][col] = content;
		nextStep(row, col, n, direct);
	}

	return matrix;
}

void nextStep(int& row, int& col, int n, enum Direction& direct) {
	switch (direct) {
		case LEFT:
			if (row + col == n - 1) {
				direct = DOWN;
				++row;
			} else {
				++col;
			}
			break;
		case RIGHT:
			if (row + col == n - 1) {
				direct = UP;
				--row;
			} else {
				--col;
			}
			break;
		case UP:
			if (row - 1 == col) {
				direct = LEFT;
				++col;
			} else {
				--row;
			}
			break;
		case DOWN:
			if (row == col) {
				direct = RIGHT;
				--col;
			} else {
				++row;
			}
			break;
	}
}