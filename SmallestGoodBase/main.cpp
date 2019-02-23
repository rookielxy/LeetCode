#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

string smallestGoodBase(const string& n);

int main() {
	string str;
	cin >> str;
	cout << smallestGoodBase(str) << endl;
}

string smallestGoodBase(const string& n) {
	stringstream ss;
	unsigned long long x;
	ss << n;
	ss >> x;
	int upper = (int)floor(log2(x));
	for (int i = upper; i >= 1; --i) {
		if (((unsigned long long)floor(pow(x, (double)1/(i+1)))) ==
		    (unsigned long long)floor(pow(x, (double)1/i)))
			continue;
		auto k = (unsigned long long)floor(pow(x, (double)1/i));
		unsigned long long temp = k + 1;
		while (temp < x)
			temp = temp*k + 1;
		if (temp == x)
			return to_string(k);
	}
	return to_string(x - 1);
}