#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

void reverseWords(string &s);

int main() {
	string str;
	getline(cin, str);
	reverseWords(str);
	cout << str << endl;
	return 0;
}

void reverseWords(string &s) {
    if (s.empty())
        return;
    stringstream ss;
    ss << s;
    string str;
    stack<string> stk;
    while (ss >> str)
        stk.push(str);
    str = "";
    while (not stk.empty()) {
        str += stk.top() + " ";
        stk.pop();
    }
    if (not str.empty())
        str.pop_back();
    s = str;
}