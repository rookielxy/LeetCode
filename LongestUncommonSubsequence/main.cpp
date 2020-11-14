#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int findLUSlength(vector<string>& strs);
bool isSubsequence(const string& s1, const string& s2);

int main() {
    vector<string> strs = {"c", "aabbcc", "aabbcc"};
    cout << findLUSlength(strs) << endl;
    return 0;
}


int findLUSlength(vector<string>& strs) {
    if (strs.empty())
        return 0;

    int ans = -1;
    for (int i = 0; i < strs.size(); ++i) {
        bool isSeq = false;
        for (int j = 0; j < strs.size(); ++j) {
            if (i == j)
                continue;
            isSeq = isSubsequence(strs[i], strs[j]);
            if (isSeq)
                break;
        }
        if (not isSeq)
            ans = max(ans, (int)strs[i].size());
    }
    return ans;
}


bool isSubsequence(const string& s1, const string& s2) {
    int p1 = 0, p2 = 0;
    while (p1 < s1.size() and p2 < s2.size()) {
        if (s1[p1] == s2[p2])
            ++p1;
        ++p2;
    }
    return p1 == s1.size();
}

