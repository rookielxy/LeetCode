#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class MyCalendar {
private:
	map<int, int> storage;
public:
	MyCalendar() = default;

	bool book(int start, int end) {
		auto it = storage.upper_bound(start);
		if (it != storage.end() and end > it->first)
			return false;
		if (it == storage.begin()) {
			storage.emplace(start, end);
			return true;
		}
		--it;
		if (start >= it->second) {
			storage.emplace(start, end);
			return true;
		}
		return false;
	}
};

int main() {
	MyCalendar calendar = MyCalendar();
	assert(calendar.book(10, 20));
	assert(not calendar.book(15, 25));
	assert(calendar.book(20, 30));
	return 0;
}