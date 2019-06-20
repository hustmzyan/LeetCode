"""
63. Unique Paths II

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.
"""
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid) -> int:
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        if obstacleGrid[0][0] == 1:
            return 0
        
        len_of_i = len(obstacleGrid)
        len_of_j = len(obstacleGrid[0])
        dp = [[0 for x in range(len_of_j)] for y in range(len_of_i)] 
        
        for i in range(0, len_of_i):
            for j in range(0, len_of_j):
                if i == 0 and j == 0:
                    dp[i][j] = 1
                elif obstacleGrid[i][j] == 1:
                    dp[i][j] = 0
                else:
                    if j - 1 >= 0:
                        dp[i][j] += dp[i][j-1]
                    if i - 1 >= 0:
                        dp[i][j] += dp[i-1][j]
                
        return dp[len_of_i-1][len_of_j-1]

def main():
    obstacle = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
    print(Solution().uniquePathsWithObstacles(obstacle))

if __name__ == "__main__":
    main()