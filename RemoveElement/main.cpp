#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val);

int main() {
    string line;
    getline(cin, line);
    stringstream ss;
    vector<int> nums;
    int data;
    ss << line;
    while(ss >> data)
        nums.push_back(data);
    cin >> data;
    cout << removeElement(nums, data) << endl;
    for(auto ele: nums)
        cout << ele << " ";
    cout << endl;
    return 0;
}

int removeElement(vector<int>& nums, int val) {
    if(nums.empty())
        return 0;
    int p = 0, q = (int)nums.size() - 1;
    int find = 0;
    while(p < q) {
        while(nums[q] == val and p < q) {
            --q;
            ++find;
        }
        while(nums[p] != val and p < q) {
            ++p;
        }
        swap(nums[p], nums[q]);
    }
    if(nums[p] == val)
        ++find;
    nums.erase(nums.end() - find, nums.end());
    return (int)nums.size();
}