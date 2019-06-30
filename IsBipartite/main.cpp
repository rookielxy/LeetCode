#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>>& graph);

int main() {
	int v;
	string str;

	vector<vector<int>> graph;
	while (getline(cin, str)) {
		vector<int> neighbors;
		stringstream ss;
		ss << str;
		while (ss >> v)
			neighbors.emplace_back(v);
		graph.emplace_back(neighbors);
	}
	if (isBipartite(graph))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}

class DisjointSet {
	vector<int> parent;

	int findParent(int k) {
		int prev = k;
		while (parent[k] != -1)
			k = parent[k];
		if (k != prev)
			parent[prev] = k;
		return k;
	}
public:
	explicit DisjointSet(size_t sz): parent(sz, -1) {}

	bool inSameSet(int x, int y) {
		return findParent(x) == findParent(y);
	}

	void unionSet(int x, int y) {
		if (inSameSet(x, y))
			return;
		x = findParent(x);
		y = findParent(y);
		assert(parent[x] == -1 and parent[y] == -1);
		parent[y] = x;
	}
};

bool isBipartite(vector<vector<int>>& graph) {

	enum Color {WHITE, BLUE, RED};
	vector<enum Color> colored(graph.size(), WHITE);

	/*
	 * 在所有连通分量上进行广度搜索，
	 * 若发现相同颜色节点相连则非二部图。
	 */

	while (true) {
		int root = -1;
		bool existUncolored = false;
		for (int i = 0; i < (int)colored.size(); ++i) {
			if (colored[i] == WHITE) {
				existUncolored = true;
				root = i;
				break;
			}
		}
		if (not existUncolored)
			break;

		colored[root] = RED;
		queue<int> q;
		q.push(root);
		while (not q.empty()) {
			int v = q.front();
			q.pop();

			for (int neighbor : graph[v]) {
				if (colored[neighbor] != WHITE) {
					if (colored[neighbor] == colored[v])
						return false;
					continue;
				}
				q.push(neighbor);
				colored[neighbor] = (colored[v] == BLUE)? RED : BLUE;
			}
		}
	}
	return true;
	/*
	auto disSet = DisjointSet(graph.size());
	for (int i = 0; i < (int)graph.size(); ++i) {
		for (int neighbor : graph[i]) {
			for (int v : graph[neighbor])
				disSet.unionSet(i, v);
		}
	}
	for (int i = 0; i < (int)graph.size(); ++i) {
		for (int neighbor : graph[i]) {
			if (disSet.inSameSet(i, neighbor))
				return false;
		}
	}
	return true;
	 */
}