#include <iostream>
#include <cassert>
#include <stack>
#include <string>

using namespace std;

bool isValid(const string &s);

int main() {
    string str;
    cin >> str;
    if(isValid(str))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}

bool isValid(const string &s) {
    if(s.empty())
        return true;
    if(not(s.front() == '{' or s.front() == '(' or s.front() == '['))
        return false;
    int s1 = 0, s2 = 0, s3 = 0;
    switch(s.front()) {
        case '(': ++s1; break;
        case '{': ++s2; break;
        case '[': ++s3; break;
        default: assert(false);
    }

    stack<char> left;
    left.push(s.front());
    for(int i = 1; i < s.size(); ++i) {
        switch(s[i]) {
            case '(':
                ++s1;
                left.push('(');
                break;
            case '{':
                ++s2;
                left.push('{');
                break;
            case '[':
                ++s3;
                left.push('[');
                break;
            case ')':
                --s1;
                if(left.empty() or left.top() != '(' or s1 < 0)
                    return false;
                left.pop();
                break;
            case '}':
                --s2;
                if(left.empty() or left.top() != '{' or s2 < 0)
                    return false;
                left.pop();
                break;
            case ']':
                --s3;
                if(left.empty() or left.top() != '[' or s3 < 0)
                    return false;
                left.pop();
                break;
            default:
                assert(false);
        }
    }
    return (s1 == 0 and s2 == 0 and s3 == 0);
}