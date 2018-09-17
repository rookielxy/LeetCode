#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

string longestPalindrome(const string &s);

int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}

string longestPalindrome(const string &s) {
    string sub;
    if(s.empty())
        return sub;
    if(s.size() == 1)
        return s;
    string str = "#";
    for(auto ch: s)
        str += ch, str += "#";

    auto arr = new int[str.size()];
    arr[0] = 1, arr[1] = 2;
    int idx = 1, right = 2, pos = 0, length = 0;
    for(int i = 2; i < str.size(); ++i) {
        if(i <= right)
            arr[i] = min(right - i, arr[2*idx - i]);
        else
            arr[i] = 1;
        while(str[i - arr[i]] == str[i + arr[i]]) {
            if(i - arr[i] < 0 || i + arr[i] >= str.size())
                break;
            ++arr[i];
        }
        if(arr[i] + i > right) {
            idx = i;
            right = arr[i] + i;
        }
        if(arr[i] > length) {
            pos = i;
            length = arr[i];
        }
    }
    return s.substr((unsigned)(pos - length + 1)/2, (unsigned)length - 1);
}