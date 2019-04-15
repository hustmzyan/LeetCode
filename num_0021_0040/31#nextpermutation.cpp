/**
 * 31. Next Permutation
 * 
 * Implement next permutation, 
 * which rearranges numbers into the lexicographically next greater permutation of numbers
 * 
 * If such arrangement is not possible, 
 * it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. 
 * Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 */
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size()-1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                int validSwap = nums[i];
                int validInt = i;
                for(int j = i; j < nums.size(); j++){
                    if(validSwap > nums[j] && nums[j] > nums[i-1]){
                        validSwap = nums[j];
                        validInt = j;
                    }
                }
                nums[validInt] = nums[i - 1];
                nums[i - 1] = validSwap;
                sort(nums.begin()+i, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};

int main() {
    vector<int> nums;
    // [1,5,8,4,7,6,5,3,1]
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(8);
    nums.push_back(4);
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(1);

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i];
        if(i < nums.size()-1){
            cout << ",";
        }
    }
    cout << " -> ";

    Solution s;
    s.nextPermutation(nums);

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i];
        if(i < nums.size()-1){
            cout << ",";
        }
    }
    cout << endl;
    return 0;
}