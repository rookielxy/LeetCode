#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValid(string S);

int main() {
	string str;
	cin >> str;
	if (isValid(str))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}

bool isValid(string S) {
	while (S.size() > 3) {
		size_t pos = S.find("abc");
		if (pos == string::npos)
			return false;
		S = S.substr(0, pos) + S.substr(pos + 3, S.size() - 3 - pos);
	}
	return S == "abc";
}