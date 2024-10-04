#include<iostream>
#include<vector>

using namespace std;

class DSU {
    vector<int> parent;
    vector<int> rank;
    public:
    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;  // Initialize each node to be its own parent
        }
    }

    int find(int el) {
        if(el == parent[el]) {
            return el;
        }

        return parent[el] = find(parent[el]);
    }

    bool _union(int x,int y) {
        int xParent = find(x);
        int yParent = find(y);

        if(xParent == yParent) {
            //if parents are same 
            //union not possible
            return false;
        }

        //or else merge
        if(rank[xParent] > rank[yParent]) {
            parent[yParent] = xParent;
        }
        else if(rank[xParent] < rank[yParent]) {
            parent[xParent] = yParent;
        }
        else {
            //if ranks are equal
            //make any one parent
            parent[yParent] = xParent;
            rank[xParent]++;
        }
        //merged successfully
        return true;
    }
};

class Solution {
    
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        vector<int> indegree(n + 1, -1);  // To detect two-parent issue
        int bl1 = -1, bl2 = -1;  // bl1 = second edge, bl2 = first edge

        // Step 1: Check for two-parent issue
        for (int i = 0; i < n; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (indegree[v] == -1) {
                // First time encountering v, mark the edge
                indegree[v] = i; 
            } else {
                // v already has a parent -> two-parent issue
                bl1 = i;        // Second parent edge
                bl2 = indegree[v];  // First parent edge
            }
        }


        cout<<bl1<<","<<bl2<<endl;
        // Step 2: Try to build the tree, skipping the second parent edge if it exists
        for (int i = 0; i < n; ++i) {
            if (i == bl1) {
                // Skip the second parent edge for now
                continue;
            }

            int u = edges[i][0];
            int v = edges[i][1];

            if (!dsu._union(u, v)) {
                // Cycle detected
                if (bl1 == -1) {
                    // No two-parent issue, just return the edge causing the cycle
                    return edges[i];
                } else {
                    // There is a two-parent issue, return the first edge causing it
                    return edges[bl2];
                }
            }
        }

        // If the graph is valid except for the two-parent issue, return the second conflicting edge
        return edges[bl1];
    }
};

int main() {
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{4,5},{5,2}};

    Solution obj;

    vector<int> ans = obj.findRedundantDirectedConnection(edges);

    cout<<ans[0]<<","<<ans[1];
}