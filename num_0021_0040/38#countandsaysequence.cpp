/**
 * 38. Count and Say
 * 
 */
#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int i = 2; i <= n; ++i)
        {
            string temp;
            for (auto it = str.begin(); it != str.end();)
            {
                int counter = 0;
                char c = *it;
                for (auto &it2 = it; it2 != str.end() && *it2 == c; it2++)
                {
                    counter++;
                }
                temp += to_string(counter) + c;
            }
            str = temp;
        }
        return str;
    }
};


int main(){

    Solution s;

    cout << s.countAndSay(5) << endl;

    return 0;
}