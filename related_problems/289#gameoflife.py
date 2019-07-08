"""
289、Game Of Life

similar ：73#

根据百度百科，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在1970年发明的细胞自动机。

给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞具有一个初始状态 live（1）即为活细胞， 或 dead（0）即为死细胞。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
- 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
- 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
- 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
- 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；

根据当前状态，写一个函数来计算面板上细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。
"""

class Solution:
    def gameOfLife(self, board) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # 初始化一个数组，用于记录每个格子周围又多少个活细胞
        record = []
        for i in range(len(board)):
            record.append([0] * len(board[i]))
        # 算出每个格子周围有多少个活细胞
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == 1:
                    self.count(i, j, record)
        for i in range(len(board)):
            for j in range(len(board[i])):
                # 活细胞致死
                if board[i][j] == 1 and (record[i][j] < 2 or record[i][j] > 3):
                    board[i][j] = 0
                    
                # 死细胞复活
                if board[i][j] == 0 and record[i][j] == 3:
                    board[i][j] = 1
    
    def count(self, i, j, record):
        # 对每个活细胞周围的八个格子都 + 1
        self.add(i - 1, j - 1, record)
        self.add(i - 1, j, record)
        self.add(i - 1, j + 1, record)
        
        self.add(i, j - 1, record)
        self.add(i, j + 1, record)
        
        self.add(i + 1, j - 1, record)
        self.add(i + 1, j, record)
        self.add(i + 1, j + 1, record)
    
    
    def add(self, i, j, record):
        # 只对有效的位置 + 1。因为给的坐标可能超出了面板的范围
        if (0 <= i <= len(record) - 1) and (0 <= j <= len(record[i]) - 1):
            record[i][j] += 1
    
def main():
    board = [[0, 1, 0], [0, 0, 1], [1, 1, 1], [0, 0, 0]]
    Solution().gameOfLife(board)
    print(board)

if __name__ == "__main__":
    main()