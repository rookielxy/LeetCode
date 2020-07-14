#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

string largestMultipleOfThree(vector<int>& digits);

int main() {
    vector<int> digits = {9, 8, 8, 6, 6};
    cout << largestMultipleOfThree(digits) << endl;
    return 0;
}

/*
string largestMultipleOfThree(vector<int>& digits) {
    sort(digits.begin(), digits.end(), [](int ele1, int ele2) -> bool { return ele1 > ele2; });

    vector<int> one, two, three, oldThree, oldTwo, oldOne;
    for (int ele : digits) {
        oldThree = three;
        oldTwo = two;
        oldOne = one;
        switch (ele % 3) {
            case 0:
                if (not one.empty())
                    one.emplace_back(ele);
                if (not two.empty())
                    two.emplace_back(ele);
                three.emplace_back(ele);
                break;
            case 1:
                if (one.empty())
                    one.emplace_back(ele);

                if (not two.empty() and two.size() + 1 > three.size()) {
                    three = two;
                    three.emplace_back(ele);
                }
                if (not oldOne.empty() and oldOne.size() + 1 > two.size()) {
                    two = oldOne;
                    two.emplace_back(ele);
                }
                if (oldThree.size() + 1 > one.size()) {
                    one = oldThree;
                    one.emplace_back(ele);
                }
                break;
            case 2:
                if (two.empty())
                    two.emplace_back(ele);
                if (not one.empty() and one.size() + 1 > three.size()) {
                    three = one;
                    three.emplace_back(ele);
                }
                 if (oldThree.size() + 1 > two.size()) {
                    two = oldThree;
                    two.emplace_back(ele);
                }
                if (not oldTwo.empty() and oldTwo.size() + 1 > one.size()) {
                    one = oldTwo;
                    one.emplace_back(ele);
                }
                break;
            default:
                assert(false);
        }
    }
    if (three.empty())
        return "";

    string answer;
    int idx = 0;
    while (idx < three.size() and three[idx] == 0)
        ++idx;

    if (idx == three.size())
        return "0";

    for (int i = idx; i < three.size(); ++i)
        answer.push_back('0' + three[i]);

    return answer;
}
*/

string largestMultipleOfThree(vector<int>& digits) {
    sort(digits.begin(), digits.end(), [](int ele1, int ele2) -> bool { return ele1 > ele2; });
    if (digits[0] == 0)
        return "0";

    int zeros = 0;
    vector<int> remainder(3, 0);
    for (int ele : digits) {
        remainder[ele % 3] += 1;
        if (ele == 0)
            ++zeros;
    }

    if ((remainder[1] == 0 and remainder[2] < 3) or
         (remainder[1] < 3 and remainder[2] == 0)) {
        if (remainder[0] == 0)
            return "";
        if (remainder[0] == zeros)
            return "0";
    }

    int sum = remainder[1] + 2*remainder[2];
    switch (sum % 3) {
        case 0: break;
        case 1:
            if (remainder[1] > 0)
                --remainder[1];
            else
                remainder[2] -= 2;
            break;
        case 2:
            if (remainder[2] > 0)
                --remainder[2];
            else
                remainder[1] -= 2;
            break;
        default: assert(false);
    }

    string ret(remainder[0] + remainder[1] + remainder[2], '0');
    int idx = 0;
    for (int ele : digits) {
        if (remainder[ele % 3] > 0) {
            ret[idx++] = (char)(ele + '0');
            remainder[ele % 3] -= 1;
        }
    }
    return ret;
}