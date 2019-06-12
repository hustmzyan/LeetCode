"""
55. Jump Game

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.


"""


class Solution:
    def canJump(self, nums):
        m = 0
        for i, n in enumerate(nums):
            if i > m:
                return False
            m = max(m, i+n)
        return True
            

def main():
    # nums = [2, 3, 1, 1, 4]
    # nums = [3, 2, 1, 0, 4]
    nums = [2, 0, 0]
    print(Solution().canJump(nums))

if __name__ == "__main__":
    main()