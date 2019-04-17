/**
 * 33. Search in Rotated Sorted Array
 * 
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 */

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /*
       
       /      |
      /mid1   |
     /        |
    /left     |
 ------------------
              |      /right
              |     /
              |    /mid2
              |   /
           
           */
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[left]) {  //mid1
                if (target >= nums[left] && target <= nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {                        //mid2
                if (target >= nums[mid] && target <= nums[right]){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);

    int target = 3;

    Solution s;

    int res = s.search(nums, target);

    cout << res << endl;

    return 0;
}