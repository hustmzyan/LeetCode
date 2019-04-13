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
        bool flag = true;
        int res = -1;
        if(dividend == 0){
            return 0;
        }
        if((divisor < 0 && dividend > 0) || (divisor > 0 && dividend < 0)){
            divisor = abs(divisor);
            dividend = abs(dividend);
            flag = false;
        }
        if(dividend < 0){
            while(dividend < 0){
                dividend -= divisor;
                res++;
            }
        }else{
            while(dividend > 0){
                dividend -= divisor;
                res++;
            }
        }
        if(flag){
            return res;
        }else{
            return -res;
        }
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