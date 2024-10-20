#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
    bool isValid(string s)
    {
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                count++;
            }
            else if (s[i] == ')')
            {
                if (count > 0)
                    count--;

                if (count < 0)
                    return false;
            }
        }
        return (count == 0);
    }

public:
    void backtrack(string s, int ind, int lc, int rc, unordered_set<string> &visited, vector<string> &ans)
    {
        // If no parentheses left to remove
        if (lc == 0 && rc == 0)
        {
            if (isValid(s))
            {
                ans.push_back(s);
            }
            return;
        }

        for (int i = ind; i < s.length(); i++)
        {
            // Skip duplicate parentheses for optimization
            if (i != ind && s[i] == s[i - 1]) 
                continue;

            if (s[i] == '(' || s[i] == ')')
            {
                string curr = s.substr(0, i) + s.substr(i + 1);
                
                if (visited.find(curr) == visited.end())
                {
                    // insert into visited
                    visited.insert(curr);
                    if (s[i] == '(' && lc > 0)
                    {
                        backtrack(curr, i, lc - 1, rc, visited, ans);
                    }
                    if (s[i] == ')' && rc > 0)
                    {
                        backtrack(curr, i, lc, rc - 1, visited, ans);
                    }
                }
            }
        }
    }

    vector<string> removeInvalidParentheses(string s)
    {
        int n = s.length();
        if (n == 0)
        {
            return {""};
        }

        // count invalid left and right parentheses
        int lc = 0, rc = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                lc++;
            }
            else if (s[i] == ')')
            {
                if (lc > 0)
                    lc--;
                else
                    rc++;
            }
        }

        vector<string> ans;
        unordered_set<string> visited;

        visited.insert(s);

        // If there are no invalid parentheses to remove, and the string is already valid
        if (isValid(s)) {
            ans.push_back(s);
            return ans;
        }

        // Start backtracking
        backtrack(s, 0, lc, rc, visited, ans);

        return ans;
    }
};

int main()
{
    string s = "(a)())()";
    Solution obj;
    vector<string> ans = obj.removeInvalidParentheses(s);

    for (string &str : ans)
    {
        for (char &c : str)
        {
            cout << c;
        }
        cout << endl;
    }
}