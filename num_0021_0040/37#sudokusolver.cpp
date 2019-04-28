/**
 * 37. Sudoku Solver
 * 
 * 填充数独9宫格
 * 
 */

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0, 0);
    }

    bool solveSudoku(vector<vector<char>> &board, int i, int j){
        // 遍历完
        if(i==9) return true;
        // 当前行遍历完
        if(j==9) return solveSudoku(board, i+1, 0);
        // 当前位置已填充
        if(board[i][j] != '.') return solveSudoku(board, i, j+1);
        // 轮流测试填入数据
        for(char c='1'; c<='9'; c++)
        {
            if(check(board, i, j, c))
            {
                board[i][j] = c;
                // 递归进入下层
                if(solveSudoku(board, i, j+1)) return true;
                // 下层失败，重置当前格数据
                board[i][j] = '.';
            }
        }     
        return false;
    }

    // 在 board[i][j] 填充 val 是否可以？
    bool check(vector<vector<char>> &board, int i, int j, char val)
    {
        // 计算出该坐标对应小9宫格第一个格的下标
        int row = i - i % 3, column = j - j % 3;
        // 判断当前行是否有该数据已存在
        for (int x = 0; x < 9; x++)
        {
            if (board[x][j] == val)
                return false;
        }
        // 判断当前列是否有该数据已存在
        for (int y = 0; y < 9; y++)
        {
            if (board[i][y] == val)
                return false;
        }
        // 判断当前9宫格是否有该数据已存在
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                if (board[row + x][column + y] == val)
                    return false;
            }
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

    s.solveSudoku(board);

    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}