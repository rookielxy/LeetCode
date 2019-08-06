#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

vector<int> parseInput();
vector<int> stringToIntegerVector(string input);
int longestArithSeqLength(const vector<int>& A);

int main() {
	string str;
	getline(cin, str);
	vector<int> input = stringToIntegerVector(str);
	cout << longestArithSeqLength(input) << endl;
	return 0;
}

vector<int> parseInput() {
	vector<int> input;
	int ele;
	string str;
	stringstream ss;

	getline(cin, str);
	ss << str;
	while (ss >> ele)
		input.emplace_back(ele);
	return input;
}

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int longestArithSeqLength(const vector<int>& A) {
	map<pair<int, int>, int> hash;
	int maxLength = 0;
	for (int i = 0; i < (int)A.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			int delta = A[i] - A[j];
			pair<int, int> pi = make_pair(i, delta), pj = make_pair(j, delta);
			if (hash.count(pj))
				hash[pi] = hash[pj] + 1;
			else
				hash[pi] = 2;
			maxLength = max(maxLength, hash[pi]);
		}
	}
	return maxLength;
}