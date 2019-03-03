#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> commonChars(vector<string>& A);

int main() {
	vector<string> A;
	string str;
	while (cin >> str)
		A.emplace_back(str);
	for (string ele : commonChars(A))
		cout << ele << " ";
	cout << endl;
	return 0;
}

vector<string> commonChars(vector<string>& A) {
	vector<vector<int>> record(A.size());
	for (vector<int> &array : record)
		array.resize(26);
	for (int i = 0; i < A.size(); ++i) {
		for (char ch : A[i]) {
			int idx = ch - 'a';
			++record[i][idx];
		}
	}
	vector<string> ret;
	for (int i = 0; i < 26; ++i) {
		int mn = INT_MAX;
		for (int j = 0; j < A.size(); ++j)
			mn = min(mn, record[j][i]);
		char ch = (char)('a' + i);
		for (int j = 0; j < mn; ++j) {
			string str;
			str.push_back(ch);
			ret.emplace_back(str);
		}
	}
	return ret;
}