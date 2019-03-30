/**
 * 18# 4Sum
 * 
 * Given an array nums of n integers and an integer target, 
 * are there elements a, b, c, and d in nums such that a + b + c + d = target? 
 * Find all unique quadruplets in the array which gives the sum of target.
 */

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        if(nums.size() < 4)
            return res;

        sort(nums.begin(), nums.end());

        // 拆分为3Sum来实现
        for(int i = 0; i < nums.size()-3; i++){
            int tar = target - nums[i];
            // 3Sum
            for(int j = i + 1; j < nums.size() - 2; j++){
                int tar2 = tar - nums[j];
                int front = j + 1;
                int rear = nums.size() - 1;
                // 2Sum
                while(front < rear){
                    // 满足要求，入栈
                    if(nums[front]+nums[rear] == tar2){
                        vector<int> one_res;
                        one_res.push_back(nums[i]);
                        one_res.push_back(nums[j]);
                        one_res.push_back(nums[front]);
                        one_res.push_back(nums[rear]);
                        res.push_back(one_res);
                    }
                    if (nums[front]+nums[rear] <= tar2){
                        do { ++front; } while (front < rear && nums[front] == nums[front - 1]);
                    }
                        
                    else if (nums[front]+nums[rear] >= tar2){
                        do { --rear; } while (front < rear && nums[rear] == nums[rear + 1]);
                    }
                }
                while(j+2<nums.size() && nums[j+1]==nums[j])
                    j++;
            }
            while(i+3<nums.size() && nums[i+1]==nums[i])
                i++;
        }
        return res;
    }
};


int main(){
    vector<int> nums;
    nums.push_back(-3);
    nums.push_back(-2);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    int target = 0;

    Solution s;

    vector<vector<int> > result = s.fourSum(nums, target);

    for(int i = 0; i < result.size(); i++){
        cout << "[ ";
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}