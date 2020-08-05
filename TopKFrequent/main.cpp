#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k);


int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    for (int ele : topKFrequent(nums, k))
        cout << ele << " ";
    cout << endl;
    return 0;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;

    for (int ele : nums)
        ++m[ele];

    priority_queue<pair<int, int>> pq;
    for (const auto& it : m)
        pq.emplace(make_pair(it.second, it.first));

    vector<int> result;
    for (int i = 0; i < k; ++i) {
        if (pq.empty())
            break;
        result.emplace_back(pq.top().second);
        pq.pop();
    }

    return result;
}
