#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries);
void erasePoint(int x, int y, int N);

int main() {
	int N, numLamp, numQuery;
	cin >> N >> numLamp >> numQuery;
	int x, y;
	vector<vector<int>> lamps;
	for (int i = 0; i < numLamp; ++i) {
		cin >> x >> y;
		vector<int> temp = { x, y };
		lamps.emplace_back(temp);
	}
	vector<vector<int>> queries;
	for (int i = 0; i < numQuery; ++i) {
		cin >> x >> y;
		vector<int> temp = { x, y };
		queries.emplace_back(temp);
	}
	vector<int> answer = gridIllumination(N, lamps, queries);
	for (int ele : answer)
		cout << ele << " ";
	cout << endl;
	return 0;
}

vector<set<int>> h;
vector<set<int>> v;
vector<set<int>> d1;
vector<set<int>> d2;
vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
	vector<int> answer(queries.size());

	h.resize((unsigned)N);
	v.resize((unsigned)N);
	d1.resize((unsigned)2*N - 1);
	d2.resize((unsigned)2*N - 1);
	for (vector<int> &lamp : lamps) {
		h[lamp[0]].insert(lamp[1]);
		v[lamp[1]].insert(lamp[0]);
		d1[lamp[1] - lamp[0] + N - 1].insert(lamp[0]);
		d2[lamp[0] + lamp[1]].insert(lamp[0]);
	}

	for (int i = 0; i < queries.size(); ++i) {
		int x = queries[i][0], y = queries[i][1];
		if (h[x].empty() and v[y].empty() and d1[y - x + N - 1].empty() and d2[x + y].empty()) {
			answer[i] = 0;
			continue;
		} else {
			answer[i] = 1;
		}
		for (int row = x - 1; row <= x + 1; ++row) {
			for (int col = y - 1; col <= y + 1; ++col) {
				erasePoint(row, col, N);
			}
		}
	}
	return answer;
}

void erasePoint(int x, int y, int N) {
	if (x >= 0 and y >= 0 and x < N and y < N) {
		h[x].erase(y);
		v[y].erase(x);
		d1[y - x + N - 1].erase(x);
		d2[x + y].erase(x);
	}
}

