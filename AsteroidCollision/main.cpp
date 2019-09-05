#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <list>

using namespace std;

vector<int> parseInput();
vector<int> asteroidCollision(vector<int>& asteroids);

int main() {
	vector<int> asteroids = parseInput();
	vector<int> ret = asteroidCollision(asteroids);
	for (int ele : ret)
		cout << ele << " ";
	cout << endl;
	return 0;
}

vector<int> parseInput() {
	string str;
	getline(cin, str);

	stringstream ss;
	ss << str;

	vector<int> nums;
	int ele;
	while (ss >> ele)
		nums.emplace_back(ele);

	return nums;
}

vector<int> asteroidCollision(vector<int>& asteroids) {
	list<int> arr(asteroids.begin(), asteroids.end());
	auto p = arr.begin();
	while (p != arr.end()) {
		auto next = p;
		++next;
		if (next != arr.end() and *p > 0 and *next < 0) {
			if (*next + *p == 0) {
				arr.erase(p);
				p = arr.erase(next);
				if (p != arr.begin())
					--p;
			} else if (*p + *next > 0) {
				arr.erase(next);
			} else {
				arr.erase(p);
				if (next != arr.begin())
					--next;
				p = next;
			}
			continue;
		}
		++p;
	}
	return vector<int>(arr.begin(), arr.end());
}