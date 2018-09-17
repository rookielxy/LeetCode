#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

inline void swap(int &a, int &b);
int kthLargestElement(int k, vector<int> &nums);
int kthElementArray(int k, int *arr, int n);
int quickPartition(int *arr, int n);

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    for(int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << kthLargestElement(k, nums);
    return 0;
}

inline void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int kthLargestElement(int k, vector<int> &nums) {
    auto arr = new int[nums.size()];
    memcpy(arr, &nums[0], sizeof(int)*nums.size());
    return kthElementArray(k, arr, (int)nums.size());
}

int kthElementArray(int k, int *arr, int n) {
    int idx = quickPartition(arr, n);
    if(k == idx + 1)
        return arr[idx];
    else if(k < idx + 1)
        return kthElementArray(k, arr, idx);
    else
        return kthElementArray(k - idx - 1, arr + idx + 1, n - idx - 1);
}


int quickPartition(int *arr, int n) {
    if(n <= 1)
        return 0;
    int base = arr[0];
    int p = 1, q = n - 1;
    while(p < q) {
        while(arr[p] > base and p < q)
            ++p;
        while(arr[q] < base and p < q)
            --q;
        swap(arr[p], arr[q]);
    }
    int idx = (arr[p] > base)? p: p - 1;
    swap(arr[0], arr[idx]);
    return idx;
}