#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class TimeMap {
	struct Tuple {
		string value;
		int timeStamp;
		Tuple(string value, int timeStamp) : value(move(value)), timeStamp(timeStamp) {}
	};
	map<string, vector<Tuple>> hash;
public:
	/** Initialize your data structure here. */
	TimeMap() = default;

	void set(const string &key, const string &value, int timestamp) {
		auto it = hash.find(key);
		if (it == hash.end()) {
			vector<Tuple> tuples;
			tuples.emplace_back(Tuple(value, timestamp));
			hash.emplace(key, tuples);
		} else {
			it->second.emplace_back(Tuple(value, timestamp));
		}
	}

	string get(const string &key, int timestamp) {
		auto it = hash.find(key);
		if (it == hash.end())
			return "";
		assert(not it->second.empty());
		if (it->second.front().timeStamp > timestamp)
			return "";
		auto tupleIt = --it->second.end();
		while (tupleIt->timeStamp > timestamp)
			--tupleIt;
		return tupleIt->value;
	}
};

int main() {
	TimeMap kv;
	kv.set("foo", "bar", 1);
	assert(kv.get("foo", 1) == "bar");
	assert(kv.get("foo", 3) == "bar");
	return 0;
}