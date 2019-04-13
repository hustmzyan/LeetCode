/**
 * 29. Divide Two Integers
 * 
 */

#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while (dvd >= dvs) {
            // 通过位运算方式，层层精确求解
            long temp = dvs, m = 1;
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }
};

int main(){

    int dividend = -2147483648, divisor = -1;

    // cout << -dividend << endl;

    Solution s;

    int res = s.divide(dividend, divisor);

    cout << res << endl;

    return 0;
}