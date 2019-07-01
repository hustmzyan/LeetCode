"""
741. Cherry Pickup (unchecked!!!)

In a N x N grid representing a field of cherries, each cell is one of three possible integers.

- 0 means the cell is empty, so you can pass through;
- 1 means the cell contains a cherry, that you can pick up and pass through;
- -1 means the cell contains a thorn that blocks your way.
 
Your task is to collect maximum number of cherries possible by following the rules below:

Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or down through valid path cells (cells with value 0 or 1);
After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells;
When passing through a path cell containing a cherry, you pick it up and the cell becomes an empty cell (0);
If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can be collected.

"""

class Solution:
    def cherryPickup(self, grid) -> int:
        """
        :type grid: List[List[int]]
        :rtype: int

        The idea is to use self.memo[(i1, j1, i2, j2)] to store the maximum number of cherries that can be collected starting from (i1, j1) to (N-1, N-1) then to(i2, j2) . Note that since I'm taking a step at each end at the same time, i1+j1 is always equal to i2+j2, therefore there are only O(N^3) states (and I'm using the full quadruple to store the state for the sake of clearness).

        """
        if grid[-1][-1] == -1: return 0
        
        # set up cache
        self.grid = grid
        self.memo = {}
        self.N = len(grid)
        
        return max(self.dp(0, 0, 0, 0), 0)

    def dp(self, i1, j1, i2, j2):
        # already stored: return 
        if (i1, j1, i2, j2) in self.memo: return self.memo[(i1, j1, i2, j2)]
        
        # end states: 1. out of grid 2. at the right bottom corner 3. hit a thorn
        N = self.N
        if i1 == N or j1 == N or i2 == N or j2 == N: return -1
        if i1 == N-1 and j1 == N-1 and i2 == N-1 and j2 == N-1: return self.grid[-1][-1]
        if self.grid[i1][j1] == -1 or self.grid[i2][j2] == -1: return -1
        
        # now can take a step in two directions at each end, which amounts to 4 combinations in total
        dd = self.dp(i1+1, j1, i2+1, j2)
        dr = self.dp(i1+1, j1, i2, j2+1)
        rd = self.dp(i1, j1+1, i2+1, j2)
        rr = self.dp(i1, j1+1, i2, j2+1)
        maxComb = max([dd, dr, rd, rr])
        
        # find if there is a way to reach the end
        if maxComb == -1:
            out = -1
        else:
            # same cell, can only count this cell once
            if i1 == i2 and j1 == j2:
                out = maxComb + self.grid[i1][j1]
            # different cell, can collect both
            else:
                out = maxComb + self.grid[i1][j1] + self.grid[i2][j2]
                
        # cache result
        self.memo[(i1, j1, i2, j2)] = out
        return out

def main():
    grid = [[0, 1, -1], [1, 0, -1], [1, 1, 1]]
    print(Solution().cherryPickup(grid))

if __name__ == "__main__":
    main()