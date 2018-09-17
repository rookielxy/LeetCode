#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

string minWindow(const string &s, const string &t);

int main() {
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t) << endl;
    return 0;
}

string minWindow(const string &s, const string &t) {
    if(s.empty() or t.empty())
        return "";
    bool contain = new bool[t.size()];
    for(int i = 0; i < t.size(); ++i)
        contain[i] = false;

    int left = 0, end = 0;
    bool find = false;
    while(not find) {
        for(int i = 0; i < t.size(); ++i) {
            if(s[end] == t[i])
                contain[i] = true;
        }
        ++end;

        int i = 0;
        for(; i < t.size(); ++i) {
            if(not contain[i])
                break;
        }
        if(i == t.size())
            find = true;
    }

    
}