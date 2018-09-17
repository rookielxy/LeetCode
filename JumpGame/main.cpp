#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

int jump(vector<int> &nums);

int main() {
    string str;
    stringstream ss;
    vector<int> nums;
    int data;

    getline(cin, str);
    ss << str;
    while(ss >> data)
        nums.push_back(data);
    cout << jump(nums) << endl;
    return 0;
}

int jump(vector<int> &nums) {
    int jump = 0, idx = 0, maxEnd = 0;
    while(maxEnd < nums.size() - 1) {
        int newEnd = min(idx + nums[idx], (int)nums.size() - 1);
        int max = maxEnd, flag = 0;
        for(int w = maxEnd + 1; w <= newEnd; ++w) {
            flag = (nums[w] + w > max)? w: flag;
            max = (nums[w] + w > max)? nums[w] + w: max;
        }
        idx = flag;
        ++jump;
        maxEnd = newEnd;
    }
    return jump;
}

