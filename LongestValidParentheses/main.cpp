#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int longestValidParentheses(const string &s);

int main() {
    ios::sync_with_stdio(false);
    string str;
    cin >> str;
    cout << longestValidParentheses(str) << endl;
    return 0;
}

int longestValidParentheses(const string &s) {
    auto array = new int[s.size()];
    memset(array, 0, s.size());
    int res = 0;
    for(int i = 1; i < s.size(); ++i) {
        if(s[i] == '(') {
            array[i] = 0;
            continue;
        }
        if(s[i - 1] == '(')
            array[i] = (i > 1)? 2 + array[i - 2]: 2;
        else {
            int idx = i - 1 - array[i - 1];
            int off = (idx > 0)? array[idx - 1]: 0;
            array[i] = (s[idx] == '(')? 2 + array[i - 1] + off: 0;
        }
        res = (array[i] > res)? array[i]: res;
    }
    return res;
}