"""
45. Jump Game II

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.

Note:

You can assume that you can always reach the last index.
"""

def jump(nums):
    ans = lastIdx = nextIdx = 0
    while nextIdx < len(nums) - 1:
        ans += 1
        lastIdx, nextIdx = nextIdx, max(i + nums[i] for i in range(lastIdx, nextIdx + 1))
    return ans

def jump2(nums):
    n = len(nums)
    if n < 2:
        return 0
    step = 0
    lc = 0  # current step can reach lc
    ln = nums[0]  # next jump will reach ln at most
    for i in range(n):
        if i > lc:  # if index beyond current step, then update lc and step to move forward
            lc = ln
            step += 1
        if i + nums[i] > ln: # if i's next jump region beyond ln, update ln then.
            ln = i + nums[i]
        # print(i, lc, ln, step)
        if ln >= n-1: # when ln can reach the end, just one more step will finish the game
            return step + 1

def main():
    nums = [2, 3, 1, 1, 4]
    print(jump2(nums))

if __name__ == "__main__":
    main()