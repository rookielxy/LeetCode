#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

int trap(vector<int>& height);

int main() {
    vector<int> height;
    int data;
    string str;
    stringstream ss;

    getline(cin, str);
    ss << str;
    while(ss >> data)
        height.push_back(data);
    cout << trap(height) << endl;
    return 0;
}

int trap(vector<int>& height) {
    if(height.size() < 2)
        return 0;

    int water = 0;
    stack<int> rec;
    rec.push(0);
    for(int i = 1; i < height.size(); ++i) {
        while(not rec.empty()) {
            if(height[i] <= height[rec.top()])
                break;
            int bottom = height[rec.top()];
            rec.pop();
            if(rec.empty())
                break;
            int distance = i - rec.top() - 1;
            water += distance*(min(height[rec.top()], height[i]) - bottom);
        }
        rec.push(i);
    }
    return water;
}