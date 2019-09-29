"""
96. Unique Binary Search Trees

return num of uBST
"""

class Solution:
    def numTrees(self, n):
        if n == 0 or n == 1:
            return 1
        Result = 0
        for i in range(n):
            LeftTrees = self.numTrees(i)
            RightTrees = self.numTrees(n - i - 1)
            Result += LeftTrees * RightTrees
        return Result


def main():
    print(Solution().numTrees(3))

if __name__ == "__main__":
    main()