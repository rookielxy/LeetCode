#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int longestValidParentheses(const string &s);

int main() {
    string input;
    cin >> input;
    cout << longestValidParentheses(input) << endl;
    return 0;
}

int longestValidParentheses(const string &s) {
    if(s.empty())
        return 0;

    auto matrix = new bool*[s.size()];
    for(int i = 0; i < s.size(); ++i) {
        matrix[i] = new bool[s.size()];
        memset(matrix[i], false, s.size());
    }

    int length = -1;
    for(int j = 0; j < s.size(); ++j) {
        for(int i = j - 1; i >= 0; --i) {
            if((j - i) % 2 == 0) {
                matrix[i][j] = false;
                continue;
            }
            if(j - i == 1) {
                matrix[i][j] = (s[i] == '(' && s[j] == ')');
            } else {
                bool cond1 = matrix[i][i + 1] && matrix[i + 2][j];
                bool cond2 = matrix[i][j - 2] && matrix[j - 1][j];
                bool cond3 = matrix[i + 1][j - 1] && (s[i] == '(' && s[j] == ')');
                matrix[i][j] = cond1 || cond2 || cond3;
            }
            length = (matrix[i][j] && j - i > length)? j - i: length;
        }
    }

    cout << '\t';
    for(int i = 0; i < s.size(); ++i)
        cout << i << '\t';
    cout << endl;
    for(int i = 0; i < s.size(); ++i) {
        cout << i << '\t';
        for(int j = 0; j < s.size(); ++j)
            cout << matrix[i][j] << '\t';
        cout << endl;
    }

    return length + 1;
}