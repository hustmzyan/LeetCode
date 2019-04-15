/**
 * 30. Substring with Concatenation of All Words
 * 
 * You are given a string, s, and a list of words, words, that are all of the same length. 
 * Find all starting indices of substring(s) in s 
 * that is a concatenation of each word in words exactly once 
 * and without any intervening characters.
 * 
 */

#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res; 
        if(s==""||words.size()==0)
            return res;
        map<string,int> m;
        int n=s.length();
        int len=words[0].length();
        int count=words.size();
        for(int i=0;i<count;i++){
            m[words[i]]++;
        }
        int k=len*count; 
        for(int i=0;i<=n-k;i++)
        {
            bool flag=true;
            map<string,int> temp=m; 
            string cur="";
            int count=0;
            for(int j=0;j<k;j++)
            {
                cur+=s[i+j];
                count++;
                if(count==len)
                {
                    temp[cur]--;
                    cur="";
                    count=0;
                }
            }
            for(auto it=temp.begin();it!=temp.end();it++){
                if(it->second>0)
                    flag=false;
            }
            if(flag)
                res.push_back(i);
        }
        return res;
    }
};

int main(){
    string s = "barfoothefoobarman";
    vector<string> words;
    words.push_back("foo");
    words.push_back("bar");

    Solution solu;
    vector<int> res = solu.findSubstring(s, words);

    cout << "[";
    for(int i = 0; i < res.size(); i++){
        cout << res[i];
        if(i < res.size()-1){
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}