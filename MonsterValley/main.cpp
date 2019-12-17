#include <iostream>
#include <vector>

using namespace std;

int minCostToGetThrough(const vector<int>& strength, const vector<int>& cost);
int minCost(int idx, int power, const vector<int>& strength, const vector<int>& cost);

int main() {
	int n;
	cin >> n;
	vector<int> strength((size_t)n);
	vector<int> cost((size_t)n);
	for (int i = 0; i < n; ++i)
		cin >> strength[i];
	for (int i = 0; i < n; ++i)
		cin >> cost[i];
	cout << minCostToGetThrough(strength, cost) << endl;
}

int minCostToGetThrough(const vector<int>& strength, const vector<int>& cost) {
	return minCost(0, 0, strength, cost);
}

int minCost(int idx, int power, const vector<int>& strength, const vector<int>& cost) {
	if (idx == (int)strength.size())
		return 0;
	if (power <= strength[idx])
		return cost[idx] + minCost(idx + 1, power + strength[idx], strength, cost);
	int notBuy = minCost(idx + 1, power, strength, cost);
	int buy = cost[idx] + minCost(idx + 1, power + strength[idx], strength, cost);
	return min(notBuy, buy);
}
