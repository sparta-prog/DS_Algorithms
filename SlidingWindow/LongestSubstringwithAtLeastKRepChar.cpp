#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int n = s.length();
        if (n < k)
        {
            return 0;
        }
        vector<int> freq(26, 0);
        // calculate frequency
        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }

        int end = 0;

        while(end < n && freq[s[end] - 'a'] >= k) {
            end++;
        }
        if(end >= n-1) 
            return end;

        int s1 = longestSubstring(s.substr(0,end),k);
        //iterate to the next valid character
        while(end < n && freq[s[end] - 'a'] < k) {
            end++;
        }

        int s2 = (end<n)?longestSubstring(s.substr(end),k):0;

        return max(s1,s2);
    }
};

int main()
{
    string s = "abbadeefbcca";
    int k = 2;

    Solution obj;

    cout << obj.longestSubstring(s, k);
}