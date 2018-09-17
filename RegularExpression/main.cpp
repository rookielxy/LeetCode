#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isMatch(const string &s, const string &p);

int main() {
    string target, pattern;
    cin >> target >> pattern;
    if(isMatch(target, pattern))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}

bool regularEqual(char c1, char c2) {
    return (c1 == c2) or (c1 == '.') or (c2 == '.');
}

bool isMatch(const string &s, const string &p) {
    string np;
    vector<bool> canRepeat;
    for(int i = 0; i < p.size(); ) {
        bool followedStar = (i + 1 < p.size()) and (p[i + 1] == '*');
        np.push_back(p[i]);
        canRepeat.push_back(followedStar);
        if(followedStar)
            i += 2;
        else
            ++i;
    }

    auto matrix = new bool*[np.size() + 1];
    for(int i = 0; i <= np.size(); ++i) {
        matrix[i] = new bool[s.size() + 1];
        memset(matrix[i], false, s.size() + 1);
    }

    matrix[0][0] = true;
    for(int j = 1; j <= np.size(); ++j)
        matrix[j][0] = matrix[j - 1][0] and canRepeat[j - 1];

    for(int i = 1; i <= np.size(); ++i) {
        for(int j = 1; j <= s.size(); ++j) {
            bool cond1 = matrix[i - 1][j - 1] and regularEqual(np[i - 1], s[j - 1]);
            bool cond2 = matrix[i - 1][j] and canRepeat[i - 1];
            bool cond3 = matrix[i][j - 1] and canRepeat[i - 1] and regularEqual(np[i - 1], s[j - 1]);
            matrix[i][j] = cond1 or cond2 or cond3;
        }
    }

    return matrix[np.size()][s.size()];
}