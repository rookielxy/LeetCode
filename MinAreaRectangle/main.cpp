#include <iostream>
#include <vector>
#include <set>

using namespace std;

int minAreaRect(vector<vector<int>>& points);

int main() {
	int x, y;
	vector<vector<int>> points;
	while (cin >> x >> y) {
		vector<int> point = {x, y};
		points.emplace_back(point);
	}
	cout << minAreaRect(points) << endl;
	return 0;
}

int minAreaRect(vector<vector<int>>& points) {
	if (points.size() < 4)
		return 0;
	set<vector<int>> hash;
	for (vector<int>& point : points)
		hash.insert(point);
	int area = INT_MAX;
	for (int i = 0; i < points.size(); ++i) {
		for (int j = i + 1; j < points.size(); ++j) {
			if ((points[i][0] - points[j][0])*(points[i][1] - points[j][1]) > 0) {
				if (hash.find({points[i][0], points[j][1]}) == hash.end())
					continue;
				if (hash.find({points[j][0], points[i][1]}) == hash.end())
					continue;
				area = min(area, (points[i][0] - points[j][0])*(points[i][1] - points[j][1]));
			}
		}
	}
	return (area == INT_MAX)? 0 : area;
}