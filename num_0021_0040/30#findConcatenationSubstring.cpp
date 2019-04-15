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
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if(words.empty()){
            return ret;
        }
        // k:子串长度
        int k = words[0].size(), start = 0;
        // 初始化计数unordered_map
        unordered_map<string, int> dict;
        for(auto s:words){
            dict[s]++;
        }
        // 以模式串长度取offset 0、1、2、...、k-1
        while(start < k){
            // vis:已经使用的子串计数unordered_map cnts:剩余未匹配子串个数
            unordered_map<string, int> vis;
            int cnts = words.size(), i = start;

            // 从主串下标开始遍历
            while(i < s.size()){
                // 取下标为i、长度为k的子串
                string t = s.substr(i, k);
                // 若dict中t子串不存在，初始化判断参数，滑动窗口
                if(!dict.count(t)){
                    vis.clear();
                    cnts = words.size();
                }
                // 当前子串t，已经使用完，回退
                else if(vis[t] == dict[t]){
                    // 从匹配起始下标开始，恢复判断参数，遇到t子串终止
                    for(int j = i - (words.size() - cnts) * k; s.substr(j, k) != t; j += k){
                        vis[s.substr(j, k)]--;
                        cnts++;
                    }
                }
                else {
                    // 满足t子串匹配条件，滑动窗口
                    vis[t]++;
                    cnts--;
                    // 满足最终条件，下标压到结果栈，滑动窗口
                    if(cnts == 0){
                        ret.push_back(i - (words.size() - 1) * k);
                        // 往前滑动一个k长度窗口
                        vis[s.substr(i - (words.size() - 1) * k, k)]--;
                        cnts = 1;
                    }
                }
                i += k;
            }
            start++;
        }
        return ret;
    }
};

int main(){
    string s = "wordgoodgoodgoodbestword";
    vector<string> words;
    words.push_back("word");
    words.push_back("good");
    words.push_back("best");
    words.push_back("good");

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