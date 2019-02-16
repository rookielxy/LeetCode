#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool isScramble(const string& s1, const string& s2);
bool isScramble(const string& s1, const string& s2, unsigned off1, unsigned off2, unsigned length);

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	if (isScramble(s1, s2))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}

enum State { TRUE, FALSE, UNKNOWN };

enum State ***memorization;
bool isScramble(const string& s1, const string& s2) {
	if (s1 == s2)
		return true;
	if (s1.size() != s2.size() or s1.empty())
		return false;

	int m = (unsigned)s1.size();
	memorization = new enum State**[m];
	for (int i = 0; i < m; ++i) {
		memorization[i] = new enum State*[m];
		for (int j = 0; j < m; ++j) {
			memorization[i][j] = new enum State[m + 1];
			for (int k = 0; k < m + 1; ++k)
				memorization[i][j][k] = UNKNOWN;
		}
	}
	return isScramble(s1, s2, 0, 0, m);
}

bool isScramble(const string& s1, const string& s2, unsigned off1, unsigned off2, unsigned length) {
	if (memorization[off1][off2][length] != UNKNOWN)
		return memorization[off1][off2][length] == TRUE;

	if (s1.substr(off1, length) == s2.substr(off2, length)) {
		memorization[off1][off2][length] = TRUE;
		return true;
	}

	for (unsigned split = 1; split < length; ++split) {
		if (isScramble(s1, s2, off1, off2, split) &&
		    isScramble(s1, s2, off1 + split, off2 + split, length - split)) {
			memorization[off1][off2][length] = TRUE;
		    return true;
		}
		if (isScramble(s1, s2, off1 + length - split, off2, split) &&
		    isScramble(s1, s2, off1, off2 + split, length - split)) {
			memorization[off1][off2][length] = TRUE;
			return true;
		}
	}
	memorization[off1][off2][length] = FALSE;
	return false;
}

/*
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
*/