#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

string decodeString(const string& s);

int main() {
    // string s1 = "3[a]2[bc]";
    string s2 = "3[a2[c]]";
    string s3 = "2[abc]3[cd]ef";
    string s4 = "abc3[cd]xyz";
    // cout << decodeString(s1) << endl;
    cout << decodeString(s2) << endl;
    cout << decodeString(s3) << endl;
    cout << decodeString(s4) << endl;
    return 0;
}

string decodeString(const string& s) {
    if (s.empty())
        return "";

    if (s[0] < '0' or s[0] > '9') {
        int idx = 0;
        while (idx < s.size() and (s[idx] < '0' or s[idx] > '9'))
            ++idx;
        return s.substr(0, idx) + decodeString(s.substr(idx, s.size() - idx));
    }

    int idx = 0;
    while (idx < s.size() and s[idx] >= '0' and s[idx] <= '9')
        ++idx;

    int rIdx = idx, depth = 0;
    while (rIdx < s.size()) {
        if (s[rIdx] == '[')
            ++depth;
        if (s[rIdx] == ']') {
            --depth;
            if (depth == 0)
                break;
        }
        ++rIdx;
    }

    int repeat = 0;
    sscanf(s.substr(0, idx).c_str(), "%d", &repeat);

    string s0;
    string s1 = decodeString(s.substr(idx + 1, rIdx - idx - 1));
    for (int i = 0; i < repeat; ++i)
        s0.append(s1);
    return s0.append(decodeString(s.substr(rIdx + 1, s.size() - rIdx - 1)));
}
