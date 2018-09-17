#include <iostream>
#include <string>

using namespace std;

string convert(const string &s, int numRows);

int main() {
    string s;
    int numRows;
    cin >> s >> numRows;
    cout << convert(s, numRows);
    return 0;
}


string convert(const string &s, int numRows) {
    string res;
    if(s.empty())
        return res;
    if(numRows < 2)
        return s;

    int sect = 2*numRows - 2;
    for(int i = 0; i < numRows; ++i) {
        int pch = i;
        while(pch < s.size()) {
            res.push_back(s[pch]);
            pch += sect - 2*i;
            if(pch >= s.size())
                break;
            if(not(i == 0 or i == numRows - 1))
                res.push_back(s[pch]);
            pch += 2*i;
        }
    }
    return res;
}