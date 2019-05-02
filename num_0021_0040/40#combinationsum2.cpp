/**
 * 40. Combination Sum 2
 * 
 * Given a set of candidate numbers (candidates) (without duplicates) and a target number(target), 
 * find all unique combinations in candidates where the candidate numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 *  - All numbers (including target) will be positive integers.
 *  - The solution set must not contain duplicate combinations.
 */

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > res;

    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort can make it easier to process
        vector<int> single;
        backt(candidates, target, 0, single, res);
        return res;
    }

    void backt(vector<int> &candidates, int target, int idx, vector<int> single, vector<vector<int> > &res) {
        for (int i = idx; i < candidates.size(); i++) {
            if (candidates[i] > target) // stop for loop since there is no possibility to meet the target.
                break;
            else if (candidates[i] == target) {
                single.push_back(candidates[i]);
                res.push_back(single);
                break; // stop for loop since all the requirement had been met
            }
            else {
                /* take it */
                single.push_back(candidates[i]);
                backt(candidates, target - candidates[i], i + 1, single, res);

                /* undo it */
                single.pop_back();
                while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) // avoid redundant process
                    i++;
            }
        }
    }
};

int main()
{
    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(5);
    candidates.push_back(2);
    candidates.push_back(1);
    candidates.push_back(2);

    Solution s;

    s.combinationSum2(candidates, 5);

    for (int i; i < s.res.size(); i++)
    {
        cout << '[';
        for (int j = 0; j < s.res[i].size(); j++)
        {
            cout << s.res[i][j] << ',';
        }
        cout << ']' << endl;
    }

    return 0;
}