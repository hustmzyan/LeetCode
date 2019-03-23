//
//  14#LongestCommonPrefix.cpp
//  LeetCode
//
//  Created by mzYan on 2019/3/23.
//  Copyright © 2019 mzYan. All rights reserved.
//

//public String longestCommonPrefix(String[] strs) {
//    if (strs.length == 0) return "";
//    String prefix = strs[0];
//    for (int i = 1; i < strs.length; i++)
//        while (strs[i].indexOf(prefix) != 0) {
//            prefix = prefix.substring(0, prefix.length() - 1);
//            if (prefix.isEmpty()) return "";
//        }
//    return prefix;
//}
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty() == 1) return "";
        else {
            int min = strs[0].length();
            for (int i = 1; i < strs.size(); i++) {
                if (min > strs[i].length())
                    min = strs[i].length();
                for (int j = 0; j < min; j++) {
                    if (strs[i][j] != strs[i - 1][j]) {
                        min = j;
                        break;
                    }
                }
            }
            return strs[0].substr(0, min);
        }
    }
};


int main(){
    vector<string> strs;
    strs.push_back("flow");
    strs.push_back("fl");
    
    Solution solution;
    
    string result = solution.longestCommonPrefix(strs);
    cout << result << endl;
    return 0;
}
