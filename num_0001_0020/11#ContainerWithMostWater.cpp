//
//  MostWater.cpp
//  11. Container With Most Water
//  Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
//  n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
//  Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
//  Created by mzYan on 2019/3/20.
//  Copyright © 2019 mzYan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = (int)height.size();
        int l = 0;
        int r = len - 1;
        int width = 0;
        int area = 0;
        while(l <= r){
            width = r - l;
            if(width * min(height[l],height[r]) > area){
                area = width * min(height[l],height[r]);
            }
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return area;
    }
};

int main(){
//    [1,8,6,2,5,4,8,3,7]
    vector<int> h;
    h.push_back(1);
    h.push_back(8);
    h.push_back(6);
    h.push_back(2);
    h.push_back(5);
    h.push_back(4);
    h.push_back(8);
    h.push_back(3);
    h.push_back(7);
    Solution s;
    cout << s.maxArea(h) << endl;
    return 0;
}
