#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution
{
    //     Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

    // A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from    position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
public:
    Solution() {

    };

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> cache(m, vector<int>(n, 0));

        // initialise the first row
        for (int i = 0; i < n; i++)
        {
            cache[0][i] = matrix[0][i];
        }

        int minPathSum = INT_MAX;

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;

                if (j >= 1)
                {
                    op1 = cache[i - 1][j - 1];
                }
                op2 = cache[i - 1][j];
                if (j < n - 1)
                {
                    op3 = cache[i - 1][j + 1];
                }

                cache[i][j] = matrix[i][j] + min({op1, op2, op3});
            }
        }

        for (int j = 0; j < n; j++)
        {
            minPathSum = min(minPathSum, cache[m - 1][j]);
        }

        return minPathSum;
    }
};

int main()
{
    vector<vector<int>> data = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}};

    Solution obj;

    //cout << obj.minFallingPathSum(data)<<endl;

    vector<vector<int>> data2 = {{17,82},{1,-44}};

    cout<<obj.minFallingPathSum(data2)<<endl;
}