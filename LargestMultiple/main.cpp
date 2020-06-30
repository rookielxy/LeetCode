#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

string largestMultipleOfThree(vector<int>& digits);

int main() {
    vector<int> digits = {0, 0, 0, 0, 0};
    cout << largestMultipleOfThree(digits) << endl;
    return 0;
}

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
