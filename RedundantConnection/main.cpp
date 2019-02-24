#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> findRedundantConnection(vector<vector<int>>& edges);

int main() {
	int x, y;
	vector<vector<int>> edges;
	while (cin >> x >> y) {
		edges.push_back({x, y});
	}
	vector<int> edge = findRedundantConnection(edges);
	cout << edge[0] << " " << edge[1] << endl;
	return 0;
}

class DisjointSet {
	vector<int> father;

	int getFather(int idx) {
		while (father[idx] != -1)
			idx = father[idx];
		return idx;
	}

public:
	explicit DisjointSet(size_t size) : father(size) {
		for (int& ele : father)
			ele = -1;
	}

	bool isConnected(int x, int y) {
		x = getFather(x);
		y = getFather(y);
		return (x != -1) and x == y;
	}

	void join(int x, int y) {
		father[getFather(x)] = getFather(y);
	}
};

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
	DisjointSet dset = DisjointSet(edges.size());
	for (vector<int> edge : edges) {
		int x = edge[0] - 1, y = edge[1] - 1;
		if (dset.isConnected(x, y))
			return edge;
		dset.join(x, y);
	}
	vector<int> edge;
	return edge;
}