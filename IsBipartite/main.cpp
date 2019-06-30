#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>>& graph);

int main() {
	int v, w;
	vector<vector<int>> graph;
	while (cin >> v >> w)
		graph.emplace_back(vector<int>{v, w});
	if (isBipartite(graph))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}

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
}