#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

int dieSimulator(int n, vector<int>& rollMax);

int main() {
    vector<int> rollMax = {1, 1, 1, 2, 2, 3};
    int n = 3;
    cout << dieSimulator(n, rollMax) << endl;
    return 0;
}


/**
 *  Dynamic Programming
 *  Define dp(n, l, k) as the amount of sequences of length n,
 *  ending with l k-th digit (1/2/3/4/5/6).
 *
 *  Recursion:
 *      1. dp(1, 1, k) = 1
 *      2. dp(n, 1, k) = sum_{i != k} sum_{j=0}^{n-1} dp(n-1, j, i)
 *      3. dp(n, l, k) = dp(n-1, l-1, k)
 *
 *  Since we don't need dp(n-1, *, *) after calculating dp(n, *, *),
 *  dp can be simplified as two dimensional matrix.
 */

int dieSimulator(int n, vector<int>& rollMax) {
    assert(rollMax.size() == 6);

    const int MOD = 1e9 + 7;

    vector<vector<int>> dp(6);
    for (int i = 0; i < 6; ++i) {
        dp[i] = vector<int>(rollMax[i], 0);
        dp[i][0] = 1;
    }

    int dpSum = 6;
    vector<long> sumLine(6, 1);
    for (int i = 1; i < n; ++i) {
        for (int row = 0; row < 6; ++row) {
            for (int col = (int)dp[row].size() - 1; col > 0 ; --col)
                dp[row][col] = dp[row][col - 1];
            dp[row][0] = (dpSum - sumLine[row]) % MOD;

            sumLine[row] = accumulate(dp[row].begin(), dp[row].end(), 0,
                                      [](int a, int b) { return (a + b) % MOD; });
        }
        dpSum = accumulate(sumLine.begin(), sumLine.end(), 0,
                           [](int a, int b) { return (a + b) % MOD; });
    }
    return (dpSum + MOD) % MOD;
}