/**
 * 35. Search Insert Position
 * 
 * Given a sorted array and a target value, return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.
 * 
 * You may assume no duplicates in the array.
 * 
 */
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid;
        int front = 0;
        int rear = nums.size() - 1;
        while(front <= rear){
            mid = (front + rear) / 2;
            if(nums[mid] > target){
                rear = mid - 1;
            }else if(nums[mid] < target){
                front = mid + 1;
            }else{
                return mid;
            }
        }
        return front;
    }
};

int main(){

    vector<int> nums;

    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);

    int target = 5;

    Solution s;

    int index = s.searchInsert(nums, target);

    cout << index << endl;

    return 0;
}