//
//  15#3Sum.cpp
//  LeetCode
//
//  Created by mzYan on 2019/3/24.
//  Copyright © 2019 mzYan. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return {};
        
        sort(nums.begin(), nums.end());
        vector<vector<int> > results;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            int j = i + 1;
            int k = nums.size() - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                    results.push_back({nums[i], nums[j], nums[k]});
                if (sum <= 0)
                    do { ++j; } while (j < k && nums[j] == nums[j - 1]);
                if (sum >= 0)
                    do { --k; } while (j < k && nums[k] == nums[k + 1]);
            }
        }
        return results;
    }
};


int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(-1);
    nums.push_back(-4);
    
    Solution s;
    vector<vector<int> > result;
    result = s.threeSum(nums);
    
    for(int i = 0; i < result.size(); i++){
        cout << "[" << result[i][0] << "," << result[i][1] << "," << result[i][2] << "]" << endl;
    }
    
    return 0;
}
