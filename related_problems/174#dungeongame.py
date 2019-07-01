"""
174. Dungeon Game

恶魔抓住了公主（P）并将她关在地牢的右下角。 地牢由M x N个房间组成，以2D网格布局。 我们英勇的骑士（K）最初位于左上角的房间，必须通过地牢来拯救公主。
骑士的初始健康点由正整数表示。 如果他的健康点在任何时候降至0或以下，他立即死亡。
有些房间是由恶魔守卫的，因此骑士进入这些房间时会失去健康（负整数）; 其他房间要么空（0），要么包含增加骑士健康的魔法球（正整数）。
为了尽快到达公主，骑士决定在每一步中仅向右或向下移动。

编写一个函数来确定骑士的最低初始健康状况，以便他能够拯救公主。

例如，给定下面的地牢，如果骑士遵循最佳路径RIGHT-> RIGHT  - > DOWN  - > DOWN，骑士的初始生命值必须至少为7。
  -2(K)  -3    3
    -5  -10    1
    10   30 -5(P)
注意：

* 骑士的健康没有上限。
* 任何房间都可以包含威胁或能力，甚至是骑士进入的第一个房间和公主被监禁的右下房间。
"""

class Solution:
    def calculateMinimumHP(self, dungeon) -> int:
        m = len(dungeon) # 行号
        n = len(dungeon[0]) # 列号
        dungeon[-1][-1] = max(1 - dungeon[-1][-1], 1)
        for i in range(m - 1)[::-1]: # 对最后一列处理
            dungeon[i][n - 1] = max(dungeon[i + 1][n - 1] - dungeon[i][n - 1], 1)
        for j in range(n - 1)[::-1]: # 对最后一行处理
            dungeon[m - 1][j] = max(dungeon[m - 1][j + 1] - dungeon[m - 1][j], 1)
        print(dungeon)
        for i in range(m - 1)[::-1]: # 行
            for j in range(n - 1)[::-1]: # 列
                dungeon[i][j] = max(min(dungeon[i+1][j] - dungeon[i][j], dungeon[i][j + 1] - dungeon[i][j]), 1)
        return dungeon[0][0]

def main():
    dungeon = [[0,0,0],[1,1,-1]]
    print(Solution().calculateMinimumHP(dungeon))

if __name__ == "__main__":
    main()