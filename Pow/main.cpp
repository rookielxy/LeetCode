#include <iostream>

using namespace std;

double myPow(double x, int n);

int main() {
	double x;
	int n;
	cin >> x >> n;
	cout << myPow(x, n) << endl;
	return 0;
}

double myPow(double x, int n) {
	bool neg = n < 0;
	long tn = neg? -n : n;
	double ret = 1.0;
	unsigned idx = 1;
	for (int i = 0; i < 32; ++i) {
		if ((tn & idx) != 0)
			ret *= x;
		x = x*x;
		idx <<= 1;
	}
	return neg? 1/ret : ret;
}