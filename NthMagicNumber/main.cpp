#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nthMagicalNumber(int N, int A, int B);
int greatestCommonDivisor(int A, int B);


int main() {
    cout << nthMagicalNumber(4, 2, 3) << endl;
    cout << nthMagicalNumber(1000000000, 39999, 40000) << endl;
    return 0;
}


int nthMagicalNumber(int N, int A, int B) {
    const int MOD = 1e9 + 7;

    int g = greatestCommonDivisor(A, B);
    int a = A / g, b = B / g;
    int round = a + b - 1;

    vector<int> magic_numbers(round, 0);
    for (int i = 0; i < a; ++i)
        magic_numbers[i] = (i + 1) * b;
    for (int i = 0; i < b - 1; ++i)
        magic_numbers[a + i] = (i + 1) * a;
    sort(magic_numbers.begin(), magic_numbers.end());
    long long offset = magic_numbers[((N - 1) % round)];

    long long factor1 = ((N - 1) / round) % MOD;
    long long factor2 = (a * b) % MOD;
    return (int)((((factor1 * factor2) % MOD + offset) * g) % MOD);
}

int greatestCommonDivisor(int A, int B) {
    if (A > B)
        swap(A, B);

    int temp;
    while ((temp = B % A) > 0) {
        B = A;
        A = temp;
    }
    return A;
}