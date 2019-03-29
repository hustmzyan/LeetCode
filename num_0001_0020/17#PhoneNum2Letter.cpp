/**
 * 17. Letter Combinations of a Phone Number
 */

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() > 0){
            vector<char> c = getDigitChar(digits[0]);
            for(int i = 0; i < c.size(); i++){
                char cs[2] = {c[i], 0};
                res.push_back(cs);
            }
        }
        for(int i = 1; i < digits.size(); i++){
            res = onestep(res, digits[i]);
        }
        return res;
    }

    vector<string> onestep(vector<string> res, char num){
        vector<string> result;
        vector<char> letter = getDigitChar(num);
        for(int i = 0; i < res.size(); i++){
            for(int j = 0; j < letter.size(); j++){
                string r = res[i] + letter[j];
                result.push_back(r);
            }
        }
        return result;
    }

    vector<char> getDigitChar(char digit){
        vector<char> chars;
        switch(digit){
            case '2':
                // chars = {'a', 'b', 'c'};
                chars.push_back('a');
                chars.push_back('b');
                chars.push_back('c');
                break;
            case '3':
                // chars = {'d', 'e', 'f'};
                chars.push_back('d');
                chars.push_back('e');
                chars.push_back('f');
                break;
            case '4':
                // chars = {'g', 'h', 'i'};
                chars.push_back('g');
                chars.push_back('h');
                chars.push_back('i');
                break;
            case '5':
                // chars = {'j', 'k', 'l'};
                chars.push_back('j');
                chars.push_back('k');
                chars.push_back('l');
                break;
            case '6':
                // chars = {'m', 'n', 'o'};
                chars.push_back('m');
                chars.push_back('n');
                chars.push_back('o');
                break;
            case '7':
                // chars = {'p', 'q', 'r', 's'};
                chars.push_back('p');
                chars.push_back('q');
                chars.push_back('r');
                chars.push_back('s');
                break;
            case '8':
                // chars = {'t', 'u', 'v'};
                chars.push_back('t');
                chars.push_back('u');
                chars.push_back('v');
                break;
            case '9':
                // chars = {'w', 'x', 'y', 'z'};
                chars.push_back('w');
                chars.push_back('x');
                chars.push_back('y');
                chars.push_back('z');
                break;
        }
        return chars;
    }
};

int main(){
    // cout << "hello" << endl;
    string digit = "234";
    vector<string> result;
    Solution s;
    result = s.letterCombinations(digit);
    cout << "[";
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << ",";
    }
    cout << "]" << endl;
    return 0;
}