#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

string add(string num1, string num2);
string multiply(string num1, string num2);
int charToDigit(char ch);
char digitToChar(int i);

int main() {
	string num1, num2;
	cin >> num1 >> num2;
	cout << multiply(num1, num2) << endl;
	return 0;
}


string multiply(string num1, string num2) {
	if (num1.size() < num2.size())
		return multiply(num2, num1);

	string ret(num1.size() + num2.size(), '0');
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	int carry = 0;
	for (int i = 0; i < num2.size(); ++i) {
		int factor = charToDigit(num2[i]);
		for (int j = 0; j < num1.size(); ++j) {
			int product = charToDigit(ret[i + j]) + factor*charToDigit(num1[j]) + carry;
			ret[i + j] = digitToChar(product%10);
			carry = product/10;
		}
		if (carry != 0) {
			int product = charToDigit(ret[i + num1.size()]) + carry;
			ret[i + num1.size()] = digitToChar(product%10);
			carry = product/10;
		}
	}
	while (ret.back() == '0' and ret.size() > 1)
		ret.pop_back();
	reverse(ret.begin(), ret.end());
	return ret;
}

inline int charToDigit(char ch) {
	assert(ch >= '0' and ch <= '9');
	return ch - '0';
}

inline char digitToChar(int i) {
	assert(i >= 0 and i <= 9);
	return (char)(i + '0');
}