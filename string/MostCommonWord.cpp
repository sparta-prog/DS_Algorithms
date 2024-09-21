#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <ctype.h>
using namespace std;

string mostCommonWord(string paragraph, vector<string> &banned)
{
    int n = paragraph.size();
    int m = banned.size();

    if (n == 0)
        return "";

    string cleanString;

    for (char c : paragraph)
    {
        // preserve spaces and add only
        if (isalpha(c) || isspace(c))
        {
            cleanString += tolower(c);
        }
    }
    unordered_map<string, int> mp;
    unordered_set<string> bannedSet(banned.begin(), banned.end());

    stringstream ss(cleanString);

    string word;
    while (ss >> word)
    {
        if (bannedSet.find(word) == bannedSet.end())
        {
            mp[word]++;
        }
    }

    int maxCount = 0;
    string ans = "";

    for (auto x : mp)
    {
        if (x.second > maxCount)
        {
            maxCount = x.second;
            ans = x.first;
        }
    }
    return ans;
}

int main()
{
    string str = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};

    cout << mostCommonWord(str, banned);
    return 0;
}