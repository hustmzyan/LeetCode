"""
74. Search a 2D Matrix
"""

class Solution:
    def searchMatrix(self, matrix, target: int) -> bool:
        if len(matrix) == 0:
            return False
        m, n = len(matrix), len(matrix[0])
        for row in range(m - 1):
            if target == matrix[row][0]:
                return True
            elif target >= matrix[row][0] and target < matrix[row + 1][0]:
                for col in range(n):
                    if target == matrix[row][col]:
                        return True
        for col in range(n):
            if target == matrix[m - 1][col]:
                return True
        return False

def main():
    matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 50]]
    target = 50
    print(Solution().searchMatrix(matrix, target))

if __name__ == "__main__":
    main()