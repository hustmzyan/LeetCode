//
//  12#Int2Roman.cpp
//  Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
//  For example, two is written as II in Roman numeral, just two one's added together. 
//  Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
//  Roman numerals are usually written largest to smallest from left to right. 
//  However, the numeral for four is not IIII. Instead, the number four is written as IV. 
//  Because the one is before the five we subtract it making four. 
//  The same principle applies to the number nine, which is written as IX. 
//  There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

//
//  Created by mzYan on 2019/3/21.
//  Copyright © 2019 mzYan. All rights reserved.
//


//Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000

#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string roman;
        int index = 1;
        while(num%10 || num/10){
            switch (index) {
                case 1:
                    roman = single(num%10, 'I', 'V', 'X') + roman;
                    break;
                case 2:
                    roman = single(num%10, 'X', 'L', 'C') + roman;
                    break;
                case 3:
                    roman = single(num%10, 'C', 'D', 'M') + roman;
                    break;
                case 4:
                    for(int i = 0; i < num%10; i++){
                        roman = 'M' + roman;
                    }
                    break;
            }
            num = num / 10;
            index++;
        }
        return roman;
    }
    
    string single(int number, char c1, char c2, char c3){
        string single_roman;
        if(number<4){
            for(int i = 0; i < number; i++){
                single_roman = single_roman + c1;
            }
        }else if (number==4){
            single_roman = single_roman + c1 + c2;
        }else if (number==5){
            single_roman = single_roman + c2;
        }else if (number < 9){
            single_roman = c2;
            for(int i = 0; i < number-5; i++){
                single_roman = single_roman + c1;
            }
        }else{
            single_roman = single_roman + c1 + c3;
        }
        return single_roman;
    }
};


int main(){
    int num = 10;
    Solution s;
    cout << s.intToRoman(num) << endl;
    return 0;
}
