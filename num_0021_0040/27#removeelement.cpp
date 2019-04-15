/**
 * 27. Remove Element
 * Given an array nums and a value val, remove all instances of that value in-place and return the new length.
 * 
 * Do not allocate extra space for another array, 
 * you must do this by modifying the input array in-place with O(1) extra memory.
 * 
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 * 
 */

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        if(nums.size() == 0){
            return count;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val){
                continue;
            }else{
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
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

    int len = s.removeElement(nums, 1);

    cout << len << endl;


    for(int i = 0; i < len; i++){
        cout << nums[i] << ',';
    }
    cout << endl;

    return 0;
}