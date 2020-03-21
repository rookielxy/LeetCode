#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void input(vector<int>& coins, int& amount);
int coinChange(vector<int>& coins, int amount);

int main() {
	vector<int> coins;
	int amount;
	input(coins, amount);
	cout << coinChange(coins, amount) << endl;
	return 0;
}

void input(vector<int>& coins, int& amount) {
//	coins = vector<int>{1, 2, 5};
//	amount = 11;
//	coins = vector<int>{186, 419,  83, 408};
//	amount = 6249;
	coins = vector<int>{71, 440, 63, 321, 461,
					    310, 467, 456, 361};
	amount = 9298;
}

/*
int recursor(const vector<int>& coins, int amount, vector<int>& mem, vector<bool>& visited) {
	if (amount == 0)
		return 0;
	if (amount < 0)
		return -1;
	if (visited[amount])
		return mem[amount];
	int minCoins = 0x3f3f3f3f;
	visited[amount] = true;
	for (int ele : coins) {
		int part = recursor(coins, amount - ele, mem, visited);
		if (part == -1)
			continue;
		minCoins = (minCoins < part + 1)? minCoins : part + 1;
	}
	if (minCoins == 0x3f3f3f3f) {
		mem[amount] = -1;
		return -1;
	}
	mem[amount] = minCoins;
	return minCoins;
}
*/

int coinChange(vector<int>& coins, int amount) {
	vector<int> mem(amount + 1, -1);
	mem[0] = 0;
	for (int i = 1; i <= amount; ++i) {
		int minCoins = 0x3f3f3f3f;
		for (int ele : coins) {
			if (i - ele >= 0 and mem[i - ele] != -1)
				minCoins = min(minCoins, mem[i - ele] + 1);
		}
		if (minCoins != 0x3f3f3f3f)
			mem[i] = minCoins;
	}
	return mem[amount];
}