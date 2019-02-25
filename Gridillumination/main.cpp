#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries);

int main() {
	int N, numLamp, numQuery;
	cin >> N >> numLamp >> numQuery;
	int x, y;
	vector<vector<int>> lamps;
	for (int i = 0; i < numLamp; ++i) {
		cin >> x >> y;
		lamps.push_back({x, y});
	}
	vector<vector<int>> queries;
	for (int i = 0; i < numQuery; ++i) {
		cin >> x >> y;
		queries.push_back({x, y});
	}
	vector<int> answer = gridIllumination(N, lamps, queries);
	for (int ele : answer)
		cout << ele << " ";
	cout << endl;
	return 0;
}


vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
	vector<int> answer(queries.size());

	map<int, int> h;
	map<int, int> v;
	map<int, int> d1;
	map<int, int> d2;
	set<pair<int, int>> turnOff;

	for (vector<int> &lamp : lamps) {
		++h[lamp[0]];
		++v[lamp[1]];
		++d1[lamp[0] - lamp[1]];
		++d2[lamp[0] + lamp[1]];
		turnOff.insert(make_pair(lamp[0], lamp[1]));
	}

	for (int i = 0; i < queries.size(); ++i) {
		int x = queries[i][0], y = queries[i][1];
		if (h[x] == 0 and v[y] == 0 and d1[x - y] == 0 and d2[x + y] == 0) {
			answer[i] = 0;
			continue;
		} else {
			answer[i] = 1;
		}
		for (int row = x - 1; row <= x + 1; ++row) {
			for (int col = y - 1; col <= y + 1; ++col) {
				if (row >= 0 and row < N and col >= 0 and col < N) {
					if (turnOff.count(make_pair(row, col))) {
						--h[row];
						--v[col];
						--d1[row - col];
						--d2[row + col];
						turnOff.erase(make_pair(row, col));
					}
				}
			}
		}
	}
	return answer;
}
