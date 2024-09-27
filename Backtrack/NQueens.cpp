#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
    unordered_set<int> cols;
    unordered_set<int> diag;
    unordered_set<int> antiDiag;

public:
    /**
     * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
     * Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
     * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
     */
    void backtrack(int row, vector<string> &board, vector<vector<string>> &result)
    {
        int n = board.size();
        if (row == n)
        {
            result.push_back(board);
            return;
        }

        // go over the columns and
        // place a queen in the next rows
        for (int col = 0; col < n; col++)
        {
            int diagConst = row + col;
            int antiDiagConst = row - col;
            /**
             * Check if cell is valid
             * Check diagonal and anti diagonal
             * Optimize this isvalid checking by using a
             * hashset to store already visited col, and diagonals
             */
            if (cols.find(col) != cols.end() || diag.find(diagConst) != diag.end() || antiDiag.find(antiDiagConst) != antiDiag.end())
            {
                continue;
            }
            //if cell is valid
            //mark valid
            cols.insert(col);
            diag.insert(diagConst);
            antiDiag.insert(antiDiagConst);

            board[row][col] = 'Q';
            //recursively call the function
            backtrack(row+1,board,result);
            //backtrack
            board[row][col] = '.';
            cols.erase(col);
            diag.erase(diagConst);
            antiDiag.erase(antiDiagConst);
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        if (n == 1)
        {
            return {{"Q"}};
        }

        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        // call helper
        backtrack(0, board, result);

        return result;
    }
};

int main()
{
    // n*n size of board
    // n -> number of queens
    Solution obj;
    int n = 4;
    vector<vector<string>> result = obj.solveNQueens(n);

    for (vector<string> &temp : result)
    {
        cout << endl;
        for (int i = 0; i < temp.size(); i++)
        {
            cout << temp[i] << " ";
        }
        cout << endl;
    }

    return 0;
}