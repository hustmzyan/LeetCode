/**
 * 20. Valid Parentheses
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * 
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 */

#include <stdio.h>
// #include <string.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            switch(c){
                case '(' :
                    stack.push_back(c);
                    break;
                case '[' :
                    stack.push_back(c);
                    break;
                case '{' :
                    stack.push_back(c);
                    break;
                case ')' :
                    if(stack.size()>0 && stack.back() == '('){
                        stack.pop_back();
                    }else{
                        return false;
                    }
                    break;
                case ']' :
                    if(stack.size()>0 && stack.back() == '['){
                        stack.pop_back();
                    }else{
                        return false;
                    }
                    break;
                case '}' :
                    if(stack.size()>0 && stack.back() == '{'){
                        stack.pop_back();
                    }else{
                        return false;
                    }
                    break;
            }
        }
        if(stack.size() == 0){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    string str = "]";
    Solution s;
    bool flag;
    flag = s.isValid(str);
    cout << flag << endl;
    return 0;
}


