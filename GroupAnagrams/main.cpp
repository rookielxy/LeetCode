#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs);

int main() {
	string str;
	vector<string> strs;
	while (cin >> str)
		strs.emplace_back(str);
	vector<vector<string>> answer = groupAnagrams(strs);
	for (vector<string>& anagram : answer) {
		for (string& word : anagram)
			cout << word << " ";
		cout << endl;
	}
	return 0;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string, vector<string>> storage;
	for (string& str : strs) {
		string hash = str;
		sort(hash.begin(), hash.end());
		storage[hash].emplace_back(str);
	}
	vector<vector<string>> ret(storage.size());
	int idx = 0;
	for (pair<string, vector<string>> tuple : storage)
		ret[idx++] = tuple.second;
	return ret;
}