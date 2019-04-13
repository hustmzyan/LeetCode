/**
 * 28. Implement strStr()
 */


#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // 匹配子串为空情况
        if(needle.length() == 0)
            return 0;
        // 主串和模式串等长，直接判断
        int l1 = haystack.length();
        int l2 = needle.length();
        int j = 0, m=0;
        if(l1 == l2){
            if(haystack.compare(needle) == 0)
                return 0;
            else
                return -1;
        }
        // 一般情况
        for(int i=0; i<=l1-l2; i++){
            if(haystack[i] == needle[0]){
                for(j = i, m=0; m<l2; j++, m++){
                    if(haystack[j] != needle[m]){
                        break;
                    }
                }
                if(m == l2)
                    return i;
            }
        }
        return -1;
    }
};

int main(){

    string Str = "mississippi";
    string str = "issi";

    // cout << str.length() << endl;

    Solution s;

    int needle = s.strStr(Str, str);

    cout << needle << endl;

    return 0;
}