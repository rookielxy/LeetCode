#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

bool isScramble(const string& s1, const string& s2);

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	if (isScramble(s1, s2))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}

bool isScramble(const string& s1, const string& s2) {
	if (s1.empty() or s1.size() != s2.size())
		return false;

	int m = (unsigned)s1.size();
	bool ***matrix = new bool**[m];
	for (int i = 0; i < m; ++i) {
		matrix[i] = new bool*[m];
		for (int j = 0; j < m; ++j) {
			matrix[i][j] = new bool[m + 1];
			memset(matrix[i][j], false, (m + 1)*sizeof(bool));
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			matrix[i][j][1] = s1[i] == s2[j];
		}
	}
	for (int length = 2; length <= m; ++length) {
		for (int i = 0; i <= m - length; ++i) {
			for (int j = 0; j <= m - length; ++j) {
				for (int split = 1; split < length; ++split) {
					bool guess = (matrix[i][j][split] && matrix[i + split][j + split][length - split])
							|| (matrix[i][j + length - split][split] && matrix[i + split][j][length - split]);
					if (guess) {
						matrix[i][j][length] = true;
						break;
					}
				}
			}
		}
	}
	return matrix[0][0][m];
}