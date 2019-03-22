//
//  13#rRoman2Int.cpp
//  LeetCode
//
//  Created by mzYan on 2019/3/22.
//  Copyright © 2019 mzYan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int slen = (int)s.size();
        int num = 0, sum = 0;
        int tmp_a, tmp_b;
        for(int i = 0; i < slen; i++){
            tmp_a = getInt(s.at(i));
            tmp_b = (i<(slen-1))? getInt(s.at(i+1)): 0;
            num = tmp_a>=tmp_b? tmp_a: -tmp_a; // 只要当前项比其后一项小，就把它减去，否则就加上。
            sum += num;
        }
        return sum;
    }
    
    int getInt(const char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};


int main(){
    string s = "MCMXCIV";
    Solution solution;
    int result = solution.romanToInt(s);
    cout << result << endl;
    return 0;
}
