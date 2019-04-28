/**
 * 36. Valid Sudoku
 * 
 * Determine if a 9x9 Sudoku board is valid. 
 * Only the filled cells need to be validated according to the following rules:
 * 
 * 1、Each row must contain the digits 1-9 without repetition.
 * 2、Each column must contain the digits 1-9 without repetition.
 * 3、Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 * 
 */

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 是否填充标记
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        // 遍历
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                // 判断不为空
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1; // num为board[i][j]对应的下表，如：5—>4
                    int k = i / 3 * 3 + j / 3;  // 9个9宫格的下标
                    // 判断横向、纵向、9宫格内是否都已使用
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        
        return true;
    }
};

int main(){

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
        };

    Solution s;

    bool flag = s.isValidSudoku(board);

    cout << flag << endl;


    return 0;
}