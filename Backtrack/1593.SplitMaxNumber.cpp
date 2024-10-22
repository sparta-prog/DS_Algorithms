#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
    int util(int ind, string& s,unordered_set<string>& vis) {
        if(ind >= s.size()) {
            return vis.size();
        }

        int maxSplits = 0;
        for(int len = 1;ind + len <= s.size();len++) {
            string temp = s.substr(ind,len);
            if(vis.find(temp) == vis.end()) 
            {
                vis.insert(temp);
                maxSplits = max(maxSplits, util(ind + len,s,vis));
                vis.erase(temp);
            }
        }
        return maxSplits;
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> vis;

        return util(0,s,vis);
    }
};

int main() 
{
    Solution obj;
    string s = "ababccc";

    cout<<obj.maxUniqueSplit(s);
}