#include <iostream>

using namespace std;

int clumsy(int N);

int main() {
	int n;
	cin >> n;
	cout << clumsy(n) << endl;
	return 0;
}

int clumsy(int N) {
    switch(N) {
        case 3: return 6;
        case 2: return 2;
        case 1: return 1;
        case 0: return 0;
        default: break;//;
    }
    int ret = N*(N-1)/(N-2) + (N-3);
    N -= 4;
    while (N >= 4) {
        ret -= N*(N-1)/(N-2) - (N-3);
        N -= 4;
    }
    switch(N) {
        case 3: ret -= 6; break;
        case 2: ret -= 2; break;
        case 1: ret -= 1; break;
        case 0: break;
        default: assert(false);
    }
    return ret;
}