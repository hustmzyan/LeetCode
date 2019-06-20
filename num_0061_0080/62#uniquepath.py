"""
62. Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
"""
import math

class Solution:
    # 递归
    def uniquePaths(self, m: int, n: int) -> int:
        if m == 1 or n == 1:
            return 1
        return self.uniquePaths(m - 1, n) + self.uniquePaths(m, n - 1)
    
    # 排列组合公式
    def uniquePaths_math(self, m: int, n: int) -> int:
        return math.factorial(m + n - 2) / math.factorial(m - 1) / math.factorial(n - 1)
    
    # 动态规划 O(m*n)
    def uniquePaths_dp(self, m: int, n: int) -> int:
        if not m or not n:
            return 0
        dp = [[1 for _ in range(n)] for _ in range(m)]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        return dp[-1][-1]

    # O(n) space 
    def uniquePaths_on(self, m, n):
        if not m or not n:
            return 0
        cur = [1] * n
        for i in range(1, m):
            for j in range(1, n):
                cur[j] += cur[j - 1]
        return cur[-1]

def main():
    print(Solution().uniquePaths_dp(32, 12))

if __name__ == "__main__":
    main()