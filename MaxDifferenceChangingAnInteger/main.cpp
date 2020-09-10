#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int maxDiff(int num);



int main() {
    cout << maxDiff(10000) << endl;
    return 0;
}


int maxDiff(int num) {
    if (num > 0 and num <= 9)
        return 8;

    string a = to_string(num), b = to_string(num);

    char to_replace;
    for (char i : a) {
        if (i < '9') {
            to_replace = i;
            break;
        }
    }
    for (char &i : a) {
        if (i == to_replace)
            i = '9';
    }

    bool change_first_digit = false;
    to_replace = '0';
    if (b[0] > '1') {
        to_replace = b[0];
        change_first_digit = true;
    } else {
        for (char i : b) {
            if (i > '1') {
                to_replace = i;
                break;
            }
        }
    }
    for (char &i : b) {
        if (i == to_replace) {
            if (change_first_digit)
                i = '1';
            else
                i = '0';
        }
    }
    return stoi(a) - stoi(b);
}