"""
48. Rotate Image

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
"""

def rotate(A):
    n = len(A)
    for i in range(int(n / 2)):
        for j in range(n - int(n / 2)):
            # ~i 位运算，~i = n-i-1
            # print(i, j, ~i, ~j)
            A[i][j], A[~j][i], A[~i][~j], A[j][~i] = A[~j][i], A[~i][~j], A[j][~i], A[i][j]
            # print(A)


def main():
    mat = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
        [13, 14, 15, 16]]
    print(mat)
    rotate(mat)
    print(mat)

if __name__ == "__main__":
    main()