"""
96. Unique Binary Search Trees

return num of uBST
"""

class Solution:
    def numTrees(self, n):
        res = [0] * (n+1)
        res[0] = 1
        for i in range(1, n+1):
            for j in range(i):
                res[i] += res[j] * res[i-1-j]
        return res[n]


def main():
    print(Solution().numTrees(3))

if __name__ == "__main__":
    main()