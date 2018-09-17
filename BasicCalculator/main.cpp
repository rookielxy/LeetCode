#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

int calculate(const string &str);

int main() {
    string str;
    getline(cin, str);
    cout << calculate(str) << endl;
    return 0;
}

int calculate(const string &str) {
    int nest = 0;
    vector<unsigned> sepe;
    for(unsigned i = 0; i < str.size(); ++i) {
        if(str[i] == '(')
            ++nest;
        else if(str[i] == ')')
            --nest;
        else {
            if(nest == 0 and (str[i] == '+' or str[i] == '-'))
                sepe.push_back(i);
        }
    }

    if(not sepe.empty()) {
        sepe.push_back((unsigned)str.size());
        int res = calculate(str.substr(0, sepe.front()));
        for(int i = 0; i < sepe.size() - 1; ++i) {
            switch(str[sepe[i]]) {
                case '+': res += calculate(str.substr(sepe[i] + 1, sepe[i + 1] - sepe[i] - 1)); break;
                case '-': res -= calculate(str.substr(sepe[i] + 1, sepe[i + 1] - sepe[i] - 1)); break;
                default: assert(false);
            }
        }
        return res;
    }

    unsigned p = 0, q = (unsigned)str.size() - 1;
    while(str[p] == ' ')
        ++p;
    while(str[q] == ' ')
        --q;
    if(str[p] == '(' and str[q] == ')')
        return calculate(str.substr(p + 1, q - p - 1));
    else
        return stoi(str.substr(p, q - p + 1));
}