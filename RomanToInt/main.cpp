#include <iostream>
#include <string>
#include <map>
#include <cassert>

using namespace std;

int romanToInt(const string &s);

int main() {
    string str;
    cin >> str;
    cout << romanToInt(str) << endl;
    return 0;
}

int romanToInt(const string &s) {
    int res = 0;
    map<char, int> dict = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                    {'C', 100}, {'D', 500}, {'M', 1000}
    };
    for(int i = 0; i < s.size() - 1; ++i) {
        int sign = (dict[s[i]] >= dict[s[i + 1]])? 1: -1;
        res += sign*dict[s[i]];
    }
    res += dict[s.back()];
    return res;
}