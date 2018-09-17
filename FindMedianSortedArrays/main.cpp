#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
double medianArray(vector<int>& nums1);

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> nums1((unsigned long)n1), nums2((unsigned long)n2);
    for(int i = 0; i < n1; ++i)
        cin >> nums1[i];
    for(int i = 0; i < n2; ++i)
        cin >> nums2[i];
    cout << findMedianSortedArrays(nums1, nums2) << endl;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    auto m = (int)nums1.size(), n = (int)nums2.size();
    if(m == 0)
        return medianArray(nums2);
    if(n == 0)
        return medianArray(nums1);
    if(m > n)
        return findMedianSortedArrays(nums2, nums1);
    int l1 = 0, r1 = 0, c1 = 0;
    int l2 = 0, r2 = 0, c2 = 0;
    int lo = 0, hi = 2*m;
    while(lo <= hi) {
        c1 = (lo + hi)/2;
        c2 = m + n - c1;
        l1 = (c1 == 0)? INT_MIN: nums1[(c1 - 1)/2];
        r1 = (c1 == 2*m)? INT_MAX: nums1[c1/2];
        l2 = (c2 == 0)? INT_MIN: nums2[(c2 - 1)/2];
        r2 = (c2 == 2*n)? INT_MAX: nums2[c2/2];

        if(l1 > r2)
            hi = c1 - 1;
        else if(l2 > r1)
            lo = c1 + 1;
        else
            break;
    }
    return (float)(max(l1, l2) + min(r1, r2))/2;
}

double medianArray(vector<int>& nums1) {
    if(nums1.empty())
        return 0;
    return (nums1.size()%2 == 1)? nums1[nums1.size()/2]:
           (float)(nums1[nums1.size()/2] + nums1[nums1.size()/2 - 1])/2;
}

