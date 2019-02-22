#include <iostream>
#include <vector>

using namespace std;

int leastOpsExpressTarget(int x, int target);

int main() {
	int x, target;
	cin >> x >> target;
	cout << leastOpsExpressTarget(x, target) << endl;
	return 0;
}

int leastOpsExpressTarget(int x, int target) {
	if (target == 0)
		return 0;
	if (x == 1)
		return target - 1;
	if (x > target) {
		return min(target * 2 - 1, (x - target) * 2);
	}
	int upper = x, ans = 0;
	while (upper < target) {
		upper *= x;
		++ans;
	}
	if (upper == target)
		return ans;
	int add = leastOpsExpressTarget(x, target - upper/x) + ans;
	if (upper - target < target) {
		int sub = leastOpsExpressTarget(x, upper - target) + ans + 1;
		return min(sub, add);
	} else {
		return add;
	}
}