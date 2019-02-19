#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int numSquarefulPerms(vector<int>& A);
int dfs(int u);
bool isSquare(int n);

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

struct Node {
	bool visited;
	vector<int> edges;
	Node() : visited(false) {}
};

vector<Node> nodes;
int numSquarefulPerms(vector<int>& A) {
	if (A.size() <= 1)
		return 0;
	nodes.resize(A.size());
	for (int i = 0; i < A.size(); ++i) {
		for (int j = i + 1; j < A.size(); ++j) {
			if (isSquare(A[i] + A[j])) {
				nodes[i].edges.emplace_back(j);
				nodes[j].edges.emplace_back(i);
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < A.size(); ++i) {
		for (Node &node : nodes)
			node.visited = false;
		ret += dfs(i);
	}
	return ret;
}

int dfs(int u) {
	nodes[u].visited = true;
	int ret = 0;
	for (int v : nodes[u].edges) {
		if (not nodes[v].visited) {
			ret += dfs(v);
		}
	}
	return ret;
}

bool isSquare(int n) {
	int factor = (int)floor(sqrt(n));
	return n == factor*factor;
}