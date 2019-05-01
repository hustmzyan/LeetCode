/**
 * 39. Combination Sum
 * 
 * Given a collection of candidate numbers (candidates) and a target number (target), 
 * find all unique combinations in candidates where the candidate numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 *  - All numbers (including target) will be positive integers.
 *  — The solution set must not contain duplicate combinations.
 */

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > re;

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // 暂存单个解的元素集
        vector<int> comb;
        for (int i = 0; i < candidates.size(); i++)
            fun(candidates, target - candidates[i], i, comb);
        return re;
    }

    void fun(vector<int> candidates, int target, int index, vector<int> comb)
    {
        comb.push_back(candidates[index]);
        if (target == 0)
        {
            re.push_back(comb);
            comb.pop_back();
            return;
        }
        else if (target < 0)
        {
            comb.pop_back();
            return;
        }
        else
        {
            for (int i = index; i < candidates.size(); i++)
            {
                fun(candidates, target - candidates[i], i, comb);
            }
        }
    }
};

int main() {
    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(5);

    Solution s;

    vector<vector<int> > res = s.combinationSum(candidates, 8);

    for (int i; i < res.size(); i++) {
        cout << '[';
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ',';
        }
        cout << ']' << endl;
    }

    return 0;
}