#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int longestOnes(vector<int>& A, int K);

int main() {
	stringstream ss;
	string str;
	vector<int> A;
	int binary;
	int K;

	getline(cin, str);
	ss << str;
	while (ss >> binary)
		A.emplace_back(binary);
	cin >> K;
	cout << longestOnes(A, K) << endl;
	return 0;
}

int longestOnes(vector<int>& A, int K) {
	if (A.empty())
		return 0;
	if (K == 0) {
		int peak = 0, length = 0;
		for (int ele : A) {
			if (ele == 1) {
				++length;
				peak = max(peak, length);
			} else {
				length = 0;
			}
		}
		return peak;
	}
	int start = 0, end = 0, length = 0;
	while (end < A.size()) {
		if (K == 0 and A[end] == 0) {
			K += (A[start] == 0)? 1 : 0;
			++start;
		} else {
			K -= (A[end] == 0)? 1 : 0;
			++end;
		}
		length = max(length, end - start);
	}
	return length;
}