/**
 * 41. First Missing Positive
 * Given an unsorted integer array, find the smallest missing positive integer.
 */

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int i;
        printnums(nums);
        for (i = 0; i < nums.size(); i++)
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]){
                cout << "swap" << i << ',' << nums[i] - 1 << endl;
                swap(nums[i], nums[nums[i] - 1]);
                printnums(nums);
            }

        for (i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1)
                return i + 1;
        return nums.size() + 1;
    }

    void printnums(vector<int> &nums){
        cout << '[';
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i];
            if(i < nums.size() - 1){
                cout << ',';
            }
        }
        cout << ']' << endl;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(6);
    nums.push_back(5);
    nums.push_back(0);
    nums.push_back(-1);

    Solution s;

    int res = s.firstMissingPositive(nums);

    cout << res << endl;

    return 0;
}