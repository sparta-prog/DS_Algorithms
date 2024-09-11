#include <iostream>
#include <vector>

using namespace std;

/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.
*/

class Solution
{
public:
    int helper(string &s, int i, int j, vector<vector<int>> &cache)
    {
        if (i >= j)
        {
            return 0;
        }

        if (cache[i][j] != -1)
        {
            return cache[i][j];
        }

        if (s[i] == s[j])
        {
            return helper(s, i + 1, j - 1, cache);
        }

        int op1 = 0,op2 = 0;
        op1 = 1 + helper(s, i + 1, j, cache);
        op2 = 1 + helper(s, i, j - 1, cache);

        return cache[i][j] = min(op1, op2);
    }
    int minInsertions(string s)
    {
        // helper function to do this
        int n = s.size();

        if (n == 0)
            return 0;

        vector<vector<int>> cache(n, vector<int>(n, -1));

        return helper(s, 0, n - 1, cache);
    }
};

int main()
{
    string data = "zjveiiwvc";

    Solution obj;

    cout << obj.minInsertions(data);
}