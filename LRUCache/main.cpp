#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

class LRUCache {
private:
	struct CacheItem {
		int key;
		int value;
		CacheItem(int key, int value): key(key), value(value) {}
	};

	int capacity;
	list<CacheItem> cacheQueue;
	unordered_map<int, list<CacheItem>::iterator> hash;
public:
	explicit LRUCache(int capacity): capacity(capacity) {}

	int get(int key) {
		auto it = hash.find(key);
		if (it == hash.end())
			return -1;
		else {
			int value = it->second->value;
			cacheQueue.erase(it->second);
			cacheQueue.emplace_back(CacheItem(key, value));
			hash[key] = --cacheQueue.end();
			return value;
		}
	}

	void put(int key, int value) {
		auto hashIt = hash.find(key);
		if (hashIt != hash.end()) {
			cacheQueue.erase(hashIt->second);
			cacheQueue.emplace_back(CacheItem(key, value));
			hash[key] = --cacheQueue.end();
			return;
		}

		if (cacheQueue.size() == capacity) {
			hash.erase(cacheQueue.front().key);
			cacheQueue.pop_front();
		}
		cacheQueue.emplace_back(CacheItem(key, value));
		hash.insert(make_pair(key, --cacheQueue.end()));
	}
};

int main() {
	LRUCache cache = LRUCache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;      // returns 1
	cache.put(3, 3);    // evicts key 2
	cout << cache.get(2) << endl;      // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	cout << cache.get(1) << endl;      // returns -1 (not found)
	cout << cache.get(3) << endl;      // returns 3
	cout << cache.get(4) << endl;      // returns 4
	return 0;
}