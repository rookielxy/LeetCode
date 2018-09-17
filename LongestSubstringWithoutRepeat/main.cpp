#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(const string &s);

int main() {
    string str;
    cin >> str;
    cout << lengthOfLongestSubstring(str) << endl;
    return 0;
}

int lengthOfLongestSubstring(const string &s) {
    if(s.empty())
        return 0;

    int max_ele = 0, last = -1;
    int table[256];
    memset(table, -1, sizeof(table));
    for(int i = 0; i < s.size(); ++i) {
        auto ord = (int)s[i];
        last = (table[ord] > last)? table[ord]: last;
        max_ele = (max_ele > i - last)? max_ele: i - last;
        table[ord] = i;
    }
    return max_ele;
}
