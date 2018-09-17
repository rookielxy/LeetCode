#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int maxArea(vector<int>& height);


int main() {
    int n;
    cin >> n;
    vector<int> height((unsigned long)n);
    for(int i = 0; i < n; ++i)
        cin >> height[i];
    cout << maxArea(height) << endl;
    return 0;
}


int maxArea(vector<int>& height) {
    assert(height.size() > 1);
    int maxArea = 0;
    int p = 0, q = (int)height.size() - 1;
    while(p < q) {
        bool cond = height[p] < height[q];
        int shortSlab = cond? height[p]: height[q];
        int area = (q - p)*shortSlab;
        maxArea = (maxArea > area)? maxArea: area;
        p = cond? p + 1: p;
        q = cond? q: q - 1;
    }
    return maxArea;
}