"""
90.subsets 2
"""

class Solution:
    def subsetsWithDup(self, S):
        res = [[]]
        S.sort()
        for i in range(len(S)):
            if i == 0 or S[i] != S[i - 1]:
                l = len(res)
            for j in range(len(res) - l, len(res)):
                res.append(res[j] + [S[i]])
                print(res)
        return res

def main():
    nums = [1, 2, 2]
    print(Solution().subsetsWithDup(nums))

if __name__ == "__main__":
    main()