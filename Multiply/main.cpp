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

string add(string num1, string num2) {
	string sum;
	if (num1.size() < num2.size())
		num1.insert(num1.size(), num2.size() - num1.size(), '0');
	if (num1.size() > num2.size())
		num2.insert(num2.size(), num1.size() - num2.size(), '0');
	int count = 0;
	for (int i = 0; i < num1.size(); ++i) {
		int n1 = charToDigit(num1[i]), n2 = charToDigit(num2[i]);
		char ch = digitToChar((n1 + n2 + count)%10);
		count = (n1 + n2 + count)/10;
		sum.push_back(ch);
	}
	if (count != 0)
		sum.push_back(digitToChar(count));
	return sum;
}

string multiply(string num1, string num2) {
	if (num1.size() < num2.size())
		return multiply(num2, num1);

	string ret;
	string b;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	for (char ch : num2) {
		string temp;
		string base;
		int factor1 = charToDigit(ch);
		for (auto ch2 : num1) {
			int factor2 = charToDigit(ch2);
			int result = factor1*factor2;
			if (result/10 > 0)
				temp = add(temp, base + digitToChar(result%10) + digitToChar(result/10));
			else
				temp = add(temp, base + digitToChar(result%10));
			base += '0';
		}
		temp = b + temp;
		ret = add(ret, temp);
		b += '0';
	}
	while (ret.back() == '0' and ret.size() > 1)
		ret.pop_back();
	reverse(ret.begin(), ret.end());
	return ret;
}

int charToDigit(char ch) {
	assert(ch >= '0' and ch <= '9');
	return ch - '0';
}

char digitToChar(int i) {
	assert(i >= 0 and i <= 9);
	return (char)(i + '0');
}