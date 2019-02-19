#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
#include <map>

using namespace std;

int numSquarefulPerms(vector<int>& A);
int dfs(int u, int pre, int depth);
bool isSquare(int n);
int factorial(int n);

int main() {
	stringstream ss;
	string str;
	int temp;
	vector<int> data;

	getline(cin, str);
	ss << str;
	while (ss >> temp)
		data.emplace_back(temp);
	cout << numSquarefulPerms(data) << endl;
	return 0;
}

/*
 * regard elements as nodes and
 * two nodes are connected only if the sum of two elements is square number,
 * squareful permutations are equal to a path consist of all nodes.
 * */


vector<vector<int>> nodes;
vector<bool> contains;
int numSquarefulPerms(vector<int>& A) {
	if (A.size() <= 1)
		return 0;
	bool same = true;
	for (int &ele : A) {
		same = same && (ele == A.front());
	}
	if (same)
		return isSquare(2*A[0])? 1 : 0;
	nodes.resize(A.size());
	contains.resize(A.size());
	for (bool ele : contains)
		ele = false;
	for (int i = 0; i < A.size(); ++i) {
		for (int j = i + 1; j < A.size(); ++j) {
			if (isSquare(A[i] + A[j])) {
				nodes[i].emplace_back(j);
				nodes[j].emplace_back(i);
			}
		}
	}

	int end = 0;
	for (vector<int> &edge : nodes) {
		if (edge.empty())
			return 0;
		if (edge.size() == 1)
			++end;
	}
	if (end > 2)
		return 0;

	int ret = 0;
	for (int i = 0; i < A.size(); ++i) {
		ret += dfs(i, -1, 1);
	}

	// there may still be duplicate permutations
	map<int, int> counter;
	for (int ele : A) {
		if (counter.find(ele) == counter.end())
			counter.emplace(ele, 1);
		else
			++counter.find(ele)->second;
	}
	int times = 1;
	for (pair<int, int> ele : counter)
		times *= factorial(ele.second);
	return ret/times;
}

int dfs(int u, int pre, int depth) {
	if (depth == nodes.size())
		return 1;
	int ret = 0;
	contains[u] = true;
	for (int v : nodes[u]) {
		if (v == pre)
			continue;
		if (not contains[v])
			ret += dfs(v, u, depth + 1);
	}
	contains[u] = false;
	return ret;
}

int factorial(int n) {
	int ans = 1;
	for (int i = 2; i <= n; ++i)
		ans *= i;
	return ans;
}

bool isSquare(int n) {
	int factor = (int)floor(sqrt(n));
	return n == factor*factor;
}