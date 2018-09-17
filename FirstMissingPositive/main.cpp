#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int firstMissingPositive(vector<int>& nums);

int main() {
    string str;
    getline(cin, str);
    stringstream s;
    s << str;
    int data;
    vector<int> nums;
    while(s >> data)
        nums.push_back(data);
    cout << firstMissingPositive(nums) << endl;
    return 0;
}

int firstMissingPositive(vector<int>& nums) {
    for(int i = 0; i < nums.size(); ++i) {
        while(nums[i] > 0 and nums[i] <= nums.size() and nums[i] != i + 1) {
            int pos = nums[i] - 1;
            if(nums[i] == nums[pos])
                break;
            swap(nums[i], nums[pos]);
        }
    }
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] != i + 1)
            return i + 1;
    }
    return (int)nums.size() + 1;
}