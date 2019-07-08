"""
73. Set Matrix Zeroes

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
"""

class Solution:
    def setZeroes(self, matrix) -> None:
        '''
        Idea:
        Use a var to store the line # of which has the first 0.
        Use that line as a mask line. update the all items in that line to 1. 
        When we meet a 0, update the mask line's same index item to 0, 
            and then update the items in current line to 0.
        Make a new loop which uses the mask line to do 'and' operation with each line. 
        At the end, change the the mask line to all 0.
        '''
        mask = -1
        high = len(matrix)
        width = len(matrix[0])
        for r in range(high):
            clear = False
            for c in range(width):
                if matrix[r][c] == 0:
                    if mask == -1:                  # Meet the first 0
                        mask = r                    # Get the mask line number
                        for i in range(width):      # The 0 in the mask line will keep 0, change other items to 1
                            matrix[mask][i] = 1 if matrix[mask][i] != 0 else 0
                        break                       # We don't want to clear the mask line 
                    else:                           # Meet any other line which has 0
                        clear = True                # Will clear the line to all 0
                    matrix[mask][c] = 0             # Update the mask.  
            if clear:
                matrix[r] = [0] * width             # Clear the current line which has 0
        if mask == -1:                              # In case of no 0 at all
            return
        for r in range(high):
            for c in range(width):                  # Use mask to do 'and' with each line
                matrix[r][c] = matrix[mask][c] and matrix[r][c]
        matrix[mask] = [0] * width                  # Clear the mask line

def main():
    mat = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
    Solution().setZeroes(mat)
    print(mat)

if __name__ == "__main__":
    main()