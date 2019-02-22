#include <iostream>
#include <string>
#include <map>

using namespace std;

string countOfAtoms(const string& forumula);
map<string, int> countAtoms(const string& formula);
int readNumber(const string& formula, unsigned& ptr);
string readChemical(const string& formula, unsigned& ptr);

int main() {
	string formula;
	cin >> formula;
	cout << countOfAtoms(formula) << endl;
	return 0;
}

string countOfAtoms(const string& forumula) {
	map<string, int> count = countAtoms(forumula);
	string str;
	for (pair<string, int> tuple : count) {
		str += tuple.first;
		if (tuple.second > 1)
			str += to_string(tuple.second);
	}
	return str;
}

map<string, int> countAtoms(const string& formula) {
	map<string, int> ret;
	unsigned ptr = 0;
	while (ptr < formula.size()) {
		if (formula[ptr] <= 'Z' and formula[ptr] >= 'A') {
			string chemical = readChemical(formula, ptr);
			int number = readNumber(formula, ptr);
			auto it = ret.find(chemical);
			if (it == ret.end())
				ret.emplace(chemical, number);
			else
				it->second += number;
		} else if (formula[ptr] == '(') {
			unsigned count = 1, idx = ++ptr, length = 0;
			while (ptr < formula.size()) {
				if (formula[ptr] == '(')
					++count;
				else if (formula[ptr] == ')')
					--count;
				++ptr;
				if (count == 0)
					break;
				++length;
			}
			map<string, int> subMap = countAtoms(formula.substr(idx, length));
			int number = readNumber(formula, ptr);
			for (pair<string, int> tuple : subMap) {
				auto it = ret.find(tuple.first);
				if (it == ret.end())
					ret.emplace(tuple.first, number*tuple.second);
				else
					it->second += number*tuple.second;
			}
		}
	}
	return ret;
}

int readNumber(const string& formula, unsigned& ptr) {
	int number;
	if (ptr == formula.size() or (not (formula[ptr] >= '0' and formula[ptr] <= '9'))) {
		number = 1;
	} else {
		number = 0;
		while (ptr < formula.size() and formula[ptr] >= '0' and formula[ptr] <= '9') {
			number = number*10 + (formula[ptr] - '0');
			++ptr;
		}
	}
	return number;
}

string readChemical(const string& formula, unsigned& ptr) {
	unsigned idx = ptr, length = 1;
	++ptr;
	while (ptr < formula.size() and formula[ptr] <= 'z' and formula[ptr] >= 'a') {
		++ptr;
		++length;
	}
	return formula.substr(idx, length);
}

