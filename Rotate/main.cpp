#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix);

int main() {
	int dimension;
	cin >> dimension;
	vector<vector<int>> matrix((unsigned)dimension);
	for (int i = 0; i < dimension; ++i) {
		for (int j = 0; j < dimension; ++j) {
			int temp;
			cin >> temp;
			matrix[i].emplace_back(temp);
		}
	}
	rotate(matrix);
	for (vector<int> &arr : matrix) {
		for (int ele : arr)
			cout << ele << " ";
		cout << endl;
	}
	return 0;
}

void rotate(vector<vector<int>>& matrix) {
	for (int i = 0; i < matrix.size()/2; ++i) {
		int length = (unsigned)matrix.size() - 2*i - 1;
		for (int j = i; j < i + length; ++j) {
			int temp = matrix[i][j];
			int ni = (unsigned)matrix.size() - i - 1,
				nj = (unsigned)matrix.size() - j - 1;
			matrix[i][j] = matrix[nj][i];
			matrix[nj][i] = matrix[ni][nj];
			matrix[ni][nj] = matrix[j][ni];
			matrix[j][ni] = temp;
		}
	}
}