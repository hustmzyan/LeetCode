/**
 * 26. Remove Duplicates from Sorted Array
 * Given a sorted array nums, remove the duplicates in-place 
 * such that each element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, 
 * you must do this by modifying the input array in-place with O(1) extra memory.
 */

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        if(nums.size() == 0){
            return count;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == nums[count]){
                continue;
            }else{
                nums[++count] = nums[i];
            }
        }
        return count+1;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);

    Solution s;

    int len = s.removeDuplicates(nums);

    cout << len << endl;


    for(int i = 0; i < len; i++){
        cout << nums[i] << ',';
    }
    cout << endl;

    return 0;
}