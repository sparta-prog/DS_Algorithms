#include<iostream>
#include<vector>

using namespace std;

//if no cycle exists return -1
class Solution {
    vector<int> count;
    vector<bool> inRec;

    int dfs(int node, vector<int> &edges)
    {
        int v = edges[node];
        inRec[node] = true;

        if(v != -1) {
            if(count[v] == -1) {
                count[v] = count[node] + 1;
                int maxCycle = dfs(v,edges);
                if(maxCycle != -1) {
                    return maxCycle;
                }

            } else if(count[v] != -1 && inRec[v]) {
                return abs(count[v] - count[node]) + 1;
            } 
        }
        inRec[node] = false;
        //cycle not found
        return -1;
    }

public:
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        count.resize(n, -1);
        inRec.resize(n, false);
        int maxCycleLen = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            // if not visited dfs call
            if (count[i] == -1 && edges[i] != -1)
            {
                count[i] = 1;
                int len = dfs(i, edges);
                maxCycleLen = max(maxCycleLen, len);
            }
        }
        return maxCycleLen;
    }
};

int main() {
    vector<int> edge = {4,3,3,4,7,2,3,3};
    Solution obj;

    cout<<obj.longestCycle(edge);
}