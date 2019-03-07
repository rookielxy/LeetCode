#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>

using namespace std;

int threeSumMulti(vector<int>& A, int target);

int main() {
	vector<int> A;
	int target, data;
	stringstream ss;
	string str;

	getline(cin, str);
	ss << str;
	while (ss >> data)
		A.emplace_back(data);
	cin >> target;
	cout << threeSumMulti(A, target) << endl;
	return 0;
}

int threeSumMulti(vector<int>& A, int target) {
	unordered_map<int, int> hash;
	vector<int> unique;
	for (int ele : A) {
		if (hash[ele] == 0)
			unique.emplace_back(ele);
		++hash[ele];
	}
	long ret = 0, MOD = 1000000007;
	sort(unique.begin(), unique.end());
	for (int lower = 0; lower < unique.size(); ++lower) {
		int p = lower, q = (int)unique.size() - 1;
		while (p <= q) {
			if (unique[lower] + unique[p] + unique[q] == target) {
				long count = 0;
				if (lower == p and p == q and hash[unique[p]] >= 3) {
					count = hash[unique[lower]];
					ret = (ret + (count*(count - 1)*(count - 2)/6)%MOD)%MOD;
				}
				if (lower == p and p < q and hash[unique[p]] >= 2) {
					count = hash[unique[lower]];
					ret = (ret + (hash[unique[q]]*count*(count - 1)/2)%MOD)%MOD;
				}
				if (lower < p and p == q and hash[unique[p]] >= 2) {
					count = hash[unique[p]];
					ret = (ret + (hash[unique[lower]]*count*(count - 1)/2)%MOD)%MOD;
				}
				if (lower != p and p != q) {
					ret = (ret + (hash[unique[lower]]*hash[unique[p]]*hash[unique[q]])%MOD)%MOD;
				}
				++p;
			} else if (unique[lower] + unique[p] + unique[q] < target) {
				++p;
			} else {
				--q;
			}
		}
	}

	return (int)ret;
}