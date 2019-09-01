"""
89. Gray Code

采用对称规律求解
"""

class Solution:
    def grayCode(self, n):
        if not n:
            return [0]
        res = [0,1]
        for i in range(2,n+1):
            for j in range(len(res)-1,-1,-1):
                res.append(res[j] | 1 << i - 1)
        return res

def main():
    print(Solution().grayCode(3))

if __name__ == "__main__":
    main()