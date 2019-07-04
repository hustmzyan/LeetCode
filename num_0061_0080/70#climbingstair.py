"""
70. Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.

Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
"""

class Solution:
    def climbStairs(self, n: int) -> int:
        # -~n  => (n+1)   位运算方式表达
        # WTF? don't understand
        return int(((1 + 5 ** .5) / 2)** - ~n / 5 ** .5 + .5)
        
    def climbStairs2(self, n: int) -> int:
        if n == 1:
            return 1
        res = [0 for i in range(n)]
        res[0], res[1] = 1, 2
        for i in range(2, n):
            res[i] = res[i-1] + res[i-2]
        return res[-1]

def main():
    print(Solution().climbStairs2(35))

if __name__ == "__main__":
    main()