#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;

int mergeStones(vector<int>& stones, int K);
int main() {
	stringstream ss;
	string str;
	int data, K;
	vector<int> stones;

	getline(cin, str);
	ss << str;
	while (ss >> data)
		stones.emplace_back(data);
	cin >> K;
	cout << mergeStones(stones, K) << endl;
	return 0;
}

int mergeStones(vector<int>& stones, int K) {
	if (stones.size() == 1)
		return 0;
	if ((stones.size() - 1)%(K - 1) != 0 or stones.size() < K)
		return -1;

	vector<int> sum(stones.size() + 1, 0);
	for (int i = 0; i < stones.size(); ++i)
		sum[i + 1] = sum[i] + stones[i];

	vector<vector<int>> dp(stones.size(), vector<int>(stones.size() + 1, 0));
	for (int length = K; length <= stones.size(); ++length) {
		for (int i = 0; i + length <= stones.size(); ++i) {
			dp[i][i + length] = INT_MAX;
			for (int k = 1; k < length; k += K - 1)
				dp[i][i + length] = min(dp[i][i + length], dp[i][i + k] + dp[i + k][i + length]);
			if ((length - 1)%(K - 1) == 0)
				dp[i][i + length] += sum[i + length] - sum[i];
		}
	}
	return dp[0][stones.size()];
}