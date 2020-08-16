#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string customSortString(const string& S, const string& T);

int main() {
    string S = "cba", T = "abcd";
    cout << customSortString(S, T) << endl;
    return 0;
}

string customSortString(const string& S, const string& T) {
    string ret = T;

    unordered_map<char, int> dict;
    for (int i = 0; i < S.size(); ++i)
        dict[S[i]] = i + 1;

    sort(ret.begin(), ret.end(), [&dict](char c1, char c2) -> bool {
        return dict[c1] < dict[c2];
    });

    return ret;
}