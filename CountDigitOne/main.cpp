#include <iostream>

using namespace std;

int countDigitOne(int n);

int main() {
	int n;
	cin >> n;
	cout << countDigitOne(n) << endl;
	return 0;
}

int countDigitOne(int n) {
	if (n == 0)
		return 0;

	int base = 1;
	while (base <= n)
		base *= 10;
	base /= 10;

	int first = n/base, rest = n%base;
	if (first == 1)
		return rest + 1 + countDigitOne(rest) + countDigitOne(base - 1);
	else
		return base + countDigitOne(rest) + first*countDigitOne(base - 1);
}