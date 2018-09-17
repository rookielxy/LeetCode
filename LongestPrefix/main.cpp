#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string> &strs);

int main() {
    vector<string> strs;
    string str;
    while(cin >> str)
        strs.push_back(str);
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}

string longestCommonPrefix(vector<string> &strs) {
    int idx = 0;
    string res;
    if(strs.empty())
        return res;
    while(idx < strs[0].size()) {
        char ch = strs[0][idx];
        bool same = true;
        for(int i = 1; i < strs.size(); ++i) {
            if(idx >= strs[i].size() || ch != strs[i][idx]) {
                same = false;
                break;
            }
        }
        if(same) {
            res.push_back(ch);
            ++idx;
        }
        else
            break;
    }
    return res;
}