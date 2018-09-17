#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>

using namespace std;

string intToRoman(int num);

int main() {
    int n;
    cin >> n;
    cout << intToRoman(n) << endl;
    return 0;
}

string intToRoman(int num) {
    assert(num >= 0 and num < 4000);
    map<int, string> dict = {
            {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"},
            {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"},
            {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"},
            {1000, "M"}

    };
    vector<int> arr = {1000, 900, 500, 400,
                       100, 90, 50, 40, 10,
                       9, 5, 4, 1};
    string str;
    for(auto ele: arr) {
        while(num >= ele) {
            num -= ele;
            str += dict[ele];
        }
    }
    return str;
}
