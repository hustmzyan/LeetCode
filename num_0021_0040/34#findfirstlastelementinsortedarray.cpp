/**
 * 34. Find First and Last Position of Element in Sorted Array
 * 
 * Given an array of integers nums sorted in ascending order, 
 * find the starting and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * f the target is not found in the array, return [-1, -1].
 * 
 */

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        bool flag = false;
        vector<int> res;
        int last_index = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target && !flag){
                res.push_back(i);
                flag = true;
            } else if(nums[i] == target && flag){
                last_index = i;
            }
        }
        if(!flag){
            res.push_back(-1);
            res.push_back(-1);
        }else if(flag && last_index == -1){
            res.push_back(res[0]);
        }else{
            res.push_back(last_index);
        }
        return res;
    }
};

int main(){
    vector<int> nums;

    // Input: nums = [5,7,7,8,8,10], target = 8

    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);

    int target = 8;

    Solution solu;

    vector<int> res = solu.searchRange(nums, target);

    cout << "[" << res[0] << "," << res[1] << "]" << endl;

    return 0;
}