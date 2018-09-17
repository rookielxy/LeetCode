#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

int candy(vector<int>& ratings);

int main() {
    string str;
    getline(cin, str);
    stringstream ss;
    int data;
    vector<int> ratings;
    ss << str;
    while(ss >> data)
        ratings.push_back(data);

    cout << candy(ratings) << endl;
    return 0;
}

int candy(vector<int>& ratings) {
    if(ratings.empty())
        return 0;
    if(ratings.size() == 1)
        return 1;
    if(ratings.size() == 2)
        return ratings[0] == ratings[1]? 2: 3;

    auto array = new int[ratings.size()];
    auto reverse = new int[ratings.size()];
    for(int i = 0; i < ratings.size(); ++i)
        array[i] = reverse[i] = 1;

    for(int i = 1; i < ratings.size(); ++i) {
        if(ratings[i] > ratings[i - 1])
            array[i] = array[i - 1] + 1;
    }
    for(int i = (int)ratings.size() - 2; i >= 0; --i) {
        if(ratings[i] > ratings[i + 1])
            reverse[i] = reverse[i + 1] + 1;
    }

    int res = 0;
    for(int i = 0; i < ratings.size(); ++i)
        res += max(array[i], reverse[i]);
    return res;
}