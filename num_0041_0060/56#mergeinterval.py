"""
56. Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

"""

class Solution:
    def merge(self, intervals):
        out = []
        for i in sorted(intervals, key=lambda i: i[0]):
            if out and i[0] <= out[-1][-1]:
                out[-1][-1] = max(out[-1][-1], i[-1])
            else:
                out += i,
        return out

def main():
    intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
    # intervals = [[2,3],[4,5],[6,7],[8,9],[1,10]]
    print(Solution().merge(intervals))

if __name__ == "__main__":
    main()