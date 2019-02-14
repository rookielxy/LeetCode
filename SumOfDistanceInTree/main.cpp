#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges);
void dfs(int point, int parent);
void dfsTopDown(int point, int parent);

int main() {
	int N;
	cin >> N;
	int u, v;
	vector<vector<int>> edges;
	while (cin >> u >> v) {
		vector<int> edge(2);
		edge[0] = u;
		edge[1] = v;
		edges.emplace_back(edge);
	}
	for (int ele : sumOfDistancesInTree(N, edges))
		cout << ele << endl;
	return 0;
}

int N;
vector<vector<int>> neighbor;
int *countSub, *disSub;

vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
	N = n;
	neighbor.resize((unsigned)N);
	for (auto &edge : edges) {
		neighbor[edge[0]].emplace_back(edge[1]);
		neighbor[edge[1]].emplace_back(edge[0]);
	}

	countSub = new int[N];
	disSub = new int[N];

	dfs(0, -1);
	dfsTopDown(0, -1);

	vector<int> ret(disSub, disSub + N);
	return ret;
}

void dfs(int point, int parent) {
	countSub[point] = 1;
	disSub[point] = 0;
	for (auto i : neighbor[point]) {
		if (i != parent) {
			dfs(i, point);
			countSub[point] += countSub[i];
			disSub[point] += (countSub[i] + disSub[i]);
		}
	}
}

void dfsTopDown(int point, int parent) {
	for (auto i : neighbor[point]) {
		if (i != parent) {
			disSub[i] = disSub[point] + N - 2*countSub[i];
			dfsTopDown(i, point);
		}
	}
}