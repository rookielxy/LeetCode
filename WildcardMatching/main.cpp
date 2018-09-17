#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

bool isMatch(const string &s, const string &p);
bool equal(char p, char s);

int main() {
    string s, p;
    cin >> s >> p;
    if(isMatch(s, p))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}

bool isMatch(const string &s, const string &p) {
    auto matrix = new bool*[p.size() + 1];
    for(int i = 0; i <= p.size(); ++i) {
        matrix[i] = new bool[s.size() + 1];
        memset(matrix[i], false, s.size() + 1);
    }
    matrix[0][0] = true;

    for(int i = 1; i <= p.size(); ++i) {
        matrix[i][0] = matrix[i - 1][0] and p[i - 1] == '*';
        for(int j = 1; j <= s.size(); ++j) {
            bool cond1 = matrix[i - 1][j - 1] and equal(p[i - 1], s[j - 1]);
            bool cond2 = matrix[i - 1][j] and p[i - 1] == '*';
            bool cond3 = matrix[i][j - 1] and p[i - 1] == '*';
            matrix[i][j] = cond1 or cond2 or cond3;
        }
    }
    for(int i = 0; i <= p.size(); ++i) {
        for(int j = 0; j <= s.size(); ++j) {
            if(matrix[i][j])
                cout << "true" << '\t';
            else
                cout << "false" << '\t';
        }
        cout << endl;
    }
    return matrix[p.size()][s.size()];
}

bool equal(char p, char s) {
    return p == s or p == '?' or p == '*';
}
