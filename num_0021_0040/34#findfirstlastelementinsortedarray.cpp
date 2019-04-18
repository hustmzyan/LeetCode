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
        vector<int> res;
        int front = 0;
        int rear = nums.size() - 1;
        int mid, first_index, last_index;
        while(front <= rear){
            mid = (front + rear) / 2;
            if(target > nums[mid]){
                front = mid + 1;
            } else if(target < nums[mid]){
                rear = mid - 1;
            } else{
                for(last_index = mid; last_index < nums.size() && nums[last_index] == target; last_index++);
                for(first_index = mid; first_index > -1 && nums[first_index] == target; first_index--);
                res.push_back(first_index + 1);
                res.push_back(last_index - 1);
                return res;
            }
        }
        res.push_back(-1);
        res.push_back(-1);
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