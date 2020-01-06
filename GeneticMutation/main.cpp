#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <queue>
#include <cassert>

using namespace std;

void parseInput(string& start, string& end, vector<string>& bank);
bool geneConnected(const string& start, const string& end);
int minMutation(const string& start, const string& end, const vector<string>& bank);

int main() {
	string start, end;
	vector<string> bank;
	parseInput(start, end, bank);
	cout << minMutation(start, end, bank) << endl;
	return 0;
}

void parseInput(string& start, string& end, vector<string>& bank) {
	cin >> start >> end;
	string availGene;
	while (cin >> availGene)
		bank.emplace_back(availGene);
}

bool geneConnected(const string& start, const string& end) {
	assert(start.size() == end.size());
	int diff = 1;
	for (int i = 0; i < (int)start.size(); ++i) {
		diff -= (start[i] == end[i])? 0 : 1;
		if (diff < 0)
			return false;
	}
	return diff == 0;
}

int minMutation(const string& start, const string& end, const vector<string>& bank) {
	bool findEnd = false;
	for (const auto& str : bank) {
		if (str == end)
			findEnd = true;
	}
	if (not findEnd)
		return -1;

	vector<string> allStr;
	allStr.emplace_back(start);
	allStr.insert(allStr.end(), bank.begin(), bank.end());
	allStr.emplace_back(end);

	vector<vector<int>> matrix(allStr.size(), vector<int>(allStr.size(), 0x3f3f3f3f));
	for (int i = 0; i < (int)allStr.size(); ++i) {
		for (int j = i + 1; j < (int)allStr.size(); ++j) {
			if (allStr[i] == allStr[j])
				continue;
			if (geneConnected(allStr[i], allStr[j]))
				matrix[i][j] = matrix[j][i] = 1;
		}
	}
	for(int k = 0; k < (int)allStr.size(); ++k) {
		for (int i = 0; i < (int)allStr.size(); ++i) {
			for (int j = 0; j < (int)allStr.size(); ++j) {
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}

	return matrix[0].back() == 0x3f3f3f3f? -1 : matrix[0].back();
}