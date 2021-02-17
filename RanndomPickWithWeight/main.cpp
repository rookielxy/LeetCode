#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    unsigned state = 0;

    // step should be a prime number
    // that ensures state is randomly distributed
    unsigned step = 1000033;
    unsigned sum = 0;
    vector<int> milestones;
public:
    explicit Solution(vector<int>& w) {
        milestones.resize(w.size());
        for (int i = 0; i < w.size(); ++i) {
            assert(w[i] >= 1);
            sum += w[i];
            milestones[i] = sum;
        }
    }

    int pickIndex() {
        state = (state + step) % sum;
        for (int i = 0; i < milestones.size(); ++i) {
            if (state < milestones[i])
                return i;
        }
        assert(false);
    }
};

int main() {
    vector<int> w = {1, 3, 6};
    auto* obj = new Solution(w);
    for (int i = 0; i < 10; ++i)
        cout << obj->pickIndex() << endl;
    return 0;
}
