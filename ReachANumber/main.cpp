#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int reachNumber(int target);

int main() {
	int target;
	cin >> target;
	cout << reachNumber(target) << endl;
	return 0;
}

// BFS solution, TLE
/*
int reachNumber(int target) {
	struct Node {
		int val;
		int step;
		Node(int val, int step): val(val), step(step) {}
	};
	queue<Node> q;
	q.push(Node(0, 0));
	while (not q.empty()) {
		Node t = q.front();
		if (t.val == target)
			return t.step;
		q.pop();
		q.push(Node(t.val + t.step + 1, t.step + 1));
		q.push(Node(t.val - t.step - 1, t.step + 1));
	}
	return 0;
}*/

int reachNumber(int target) {
	target = abs(target);
	int n = (int)floor(sqrt(2*target));
	if (target > n*(n + 1)/2)
		++n;
	int diff = n*(n + 1)/2 - target;
	if (diff % 2 and n % 2 == 0)
		return n + 1;
	else if (diff % 2)
		return n + 2;
	else
		return n;
}