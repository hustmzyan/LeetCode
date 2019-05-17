"""
51. N-Queens 2

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

任何两个皇后不能处于同一行、同一列、同一斜线
"""

class Solution:
    def totalNQueens(self, n: int):
        def DFS(queens, xy_dif, xy_sum):
            p = len(queens) # 当前解已确定的皇后个数
            if p==n: # 满足条件，结束判定
                result.append(queens)
                return None
            for q in range(n):  # 逐行遍历
                # (p, q)为皇后坐标，p-q 用于判定45°，p+q 用于判定135°方向
                if q not in queens and p - q not in xy_dif and p + q not in xy_sum:
                    # print(queens, xy_dif, xy_sum)
                    DFS(queens + [q], xy_dif + [p - q], xy_sum + [p + q])  # 深度优先进行递归
                    
        result = []
        DFS([],[],[])
        return len(result)

def main():
    print(Solution().totalNQueens(4))

if __name__ == "__main__":
    main()