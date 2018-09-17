#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool isNumber(const string &s);

int main() {
    string str;
    getline(cin, str);
    if(isNumber(str))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}

bool isNumber(const string &s) {
    string INT = R"([+-]?[0-9]+)";
    string FLOAT = R"([+-]?([0-9]*\.[0-9]+|[0-9]+\.))";
    string EXPO = R"([+-]?([0-9]+|([0-9]*\.[0-9]+|[0-9]+\.))[Ee][+-]?[0-9]+)";
    if(regex_match(s, regex(R"(\s*)" + INT + R"(\s*)")))
        return true;
    if(regex_match(s, regex(R"(\s*)" + FLOAT + R"(\s*)")))
        return true;
    return regex_match(s, regex(R"(\s*)" + EXPO + R"(\s*)"));
}