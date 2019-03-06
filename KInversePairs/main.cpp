#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

int kInversePairs(int n, int k);

int main() {
	int n, k;
	cin >> n >> k;
	cout << kInversePairs(n, k) << endl;
	return 0;
}

int kInversePairs(int n, int k) {
	if (k == 0 or k == n*(n - 1)/2)
		return 1;
	if (k < 0 or k > n*(n - 1)/2)
		return 0;
	const int MOD = 1e9+7;
	vector<vector<int>> dp((size_t)n + 1, vector<int>((size_t)k + 1, 0));
	dp[1][0] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i][0] = 1;
		for (int j = 1; j <= min(k, i*(i - 1)/2); ++j) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
			if (j >= i)
				dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + MOD) % MOD;
		}
	}
	return dp[n][k];
}