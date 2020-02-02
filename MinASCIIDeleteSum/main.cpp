#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

int minimumDeleteSum(const string& s1, const string& s2);

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << minimumDeleteSum(s1, s2) << endl;
	return 0;
}

int minimumDeleteSum(const string& s1, const string& s2) {
	int m = s1.size(), n = s2.size();
	vector<vector<int>> matrix(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; ++i)
		matrix[0][i] = matrix[0][i - 1] + s2[i - 1];
	for (int i = 1; i <= m; ++i)
		matrix[i][0] = matrix[i - 1][0] + s1[i - 1];
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (s1[i - 1] == s2[j - 1])
				matrix[i][j] = matrix[i - 1][j - 1];
			else {
				int c2 = matrix[i][j - 1] + s2[j - 1],
					c3 = matrix[i - 1][j] + s1[i - 1];
				matrix[i][j] = min(c2, c3);
			}
		}
	}
	return matrix[m][n];
}