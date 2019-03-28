//
//  16#3SumClosest.cpp
//  LeetCode
//
//  Created by mzYan on 2019/3/28.
//  Copyright © 2019 mzYan. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        int result = 0;
        int distance= INT_MAX;
        for (auto i = 0; i < nums.size() - 2; ++i) {
            
            int j = i + 1;
            int k = (int)(nums.size() - 1);
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                    return target;
                if (sum < target){
                    if(target-sum < distance){
                        result = sum;
                        distance = target - sum;
                    }
                    do { ++j; } while (j < k && nums[j] == nums[j - 1]);
                }
                if (sum > target){
                    if(sum-target < distance){
                        result = sum;
                        distance = sum - target;
                    }
                    do { --k; } while (j < k && nums[k] == nums[k + 1]);
                }
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-3);
    
    int target = 1;
    
    Solution s;
    
    int result = s.threeSumClosest(nums, target);
    
    cout << result << endl;
    
    return 0;
}
