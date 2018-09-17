#include <iostream>

using namespace std;

int divide(int dividend, int divisor);

int main() {
    int m, n;
    cin >> m >> n;
    cout << divide(m, n) << endl;
    return 0;
}

int divide(int dividend, int divisor) {
    bool neg = (dividend < 0 or divisor < 0) and (dividend >= 0 or divisor >= 0);
    dividend = (dividend < 0)? dividend: -dividend;
    divisor = (divisor < 0)? divisor: -divisor;

    if(dividend > divisor)
        return 0;
    unsigned base = 1, res = 0;
    while((divisor << 1) >= dividend and (divisor << 1) < divisor) {
        base <<= 1;
        divisor <<= 1;
    }
    dividend -= divisor;
    res += base;

    while(dividend < 0) {
        if(dividend <= divisor) {
            dividend -= divisor;
            res += base;
        }
        divisor >>= 1;
        base >>= 1;
    }

    if(res == INT_MIN)
        return neg? INT_MIN: INT_MAX;
    else
        return neg? -res: res;
}