#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

/*
You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.
*/

using namespace std;

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        int n = words.size();
        int len = 0;
        bool centreWord = false;

        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[words[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            string word = words[i];
            string rev = word;

            reverse(rev.begin(), rev.end());

            if (word != rev)
            {
                if (mp[word] > 0 && mp[rev] > 0)
                {
                    len += 4;
                    mp[word]--;
                    mp[rev]--;
                }
            }

            else
            {
                // word == rev
                if (mp[word] >= 2)
                {
                    mp[word] -= 2;
                    len += 4;
                }
                else if (mp[word] >= 1 && centreWord == false)
                {
                    mp[word]--;
                    centreWord = true;
                    len += 2;
                }
            }
        }
        return len;
    }
};

int main()
{
    Solution obj;

    vector<string> words = {"cc","ll","xx"};

    cout << obj.longestPalindrome(words);
}
