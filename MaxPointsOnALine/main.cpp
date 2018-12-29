#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

struct Point {
 	int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct Slope {
	int x;
	int y;
	Slope() = default;
	Slope(int x, int y): x(x), y(y) {
		Simplify();
	}

	void Simplify() {
		int a = min(x, y), b = max(x, y);
		while (a != 0) {
			int temp = a;
			a = b%a;
			b = temp;
		}
		x /= b;
		y /= b;
	}

	bool operator==(const Slope& slope) {
		return x == slope.x and y == slope.y;
	}
};


int maxPoints(vector<Point>& points);

int main() {
	int x, y;
	cin >> x >> y;
	Slope s = Slope(x, y);
	cout << s.x << " " << s.y << endl;
	return 0;
}

bool operator==(const Point& p1, const Point& p2) {
	return p1.x == p2.x and p1.y == p2.y;
}

int maxPoints(vector<Point>& points) {
	for (int i = 0; i < points.size(); ++i) {
		unordered_map<Slope, int> record;
		int duplicate = 0;
		for (int j = 0; j < points.size(); ++j) {
			if (points[i] == points[j]) {
				++duplicate;
				continue;
			}
			Slope slope = Slope(points[j].x - points[i].x, points[j].y - points[i].y);
			if (record.find(slope) == record.end())
				record[slope] = 1;
			else
				++record[slope];
		}

	}
}