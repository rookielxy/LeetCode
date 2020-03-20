#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void input(vector<vector<int>>& courses);
int scheduleCourse(vector<vector<int>>& courses);

int main() {
	vector<vector<int>> courses;
	input(courses);
	cout << scheduleCourse(courses) << endl;
	return 0;
}

void input(vector<vector<int>>& courses) {
//	int length, duration;
//	while (cin >> length >> duration) {
//		courses.emplace_back(vector<int>{length, duration});
//	}

	// test case 1
//	courses = vector<vector<int>>(4);
//	courses[0] = vector<int>{100, 200};
//	courses[1] = vector<int>{200, 1300};
//	courses[2] = vector<int>{1000, 1250};
//	courses[3] = vector<int>{2000, 3200};

	// test case 2
	courses = vector<vector<int>>{
		vector<int>{7, 16},
		vector<int>{2, 3},
		vector<int>{3, 12},
		vector<int>{3, 14},
		vector<int>{10, 19},
		vector<int>{10, 16},
		vector<int>{6, 8},
		vector<int>{6, 11},
		vector<int>{3, 13},
		vector<int>{6, 16}
	};

}

int scheduleCourse(vector<vector<int>>& courses) {
	if (courses.empty())
		return 0;
	priority_queue<int> p;
	int end = 0;
	for (const auto& c : courses) {
		if (end + c[0] <= c[1]) {
			p.push(c[0]);
			end += c[0];
		} else {
			if (not p.empty() and p.top() > c[0]) {
				end -= (p.top() - c[0]);
				p.pop();
				p.push(c[0]);
			}
		}
	}
	return p.size();
}