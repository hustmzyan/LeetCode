"""
78. Subsets

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

"""
from itertools import combinations

class Solution:
    def subsets(self, nums):
        res = [[]]
        for i in range(1, len(nums) + 1):
            for s in combinations(nums, i):
                res.append(list(s))
        return res

def main():
    nums = [1, 2, 3]
    print(Solution().subsets(nums))

if __name__ == "__main__":
    main()