#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int res = 0;
        // 1 row initialise
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = matrix[i][0];
            res += matrix[i][0];
            cout << dp[i][0] << " ";
        }
        // 1 col initialise
        for (int j = 1; j < n; j++)
        {
            dp[0][j] = matrix[0][j];
            res += matrix[0][j];
            cout << dp[0][j] << " ";
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 1)
                {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    res += dp[i][j];
                }
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return res;
    }
};