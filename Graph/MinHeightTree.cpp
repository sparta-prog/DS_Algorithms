#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    /**
     * A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
     * 
     * Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
     * 
     * Return a list of all MHTs' root labels. You can return the answer in any order.
     * The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
    */
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //edges are given
        int edge = edges.size();
        if(edge<0)
            return {};

        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        vector<bool> visited(n,false);

        for(int i=0;i<edge;i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            indegree[u]++;
            indegree[v]++;
        }

        queue<int> q;

        for(int i=0;i<n;i++) {
            if(indegree[i] == 1) {
                q.push(i);
            } 
        }

        //the last two or one element remaining is the answer
        while(n > 2) {
            int size = q.size();
            int n = n - size;

            while(size--) {
                int node = q.front();

                for(int x: adj[node]) {
                    if(!visited[x]) {
                        //decrease indegree
                        indegree[x]--;
                        if(indegree[x] == 1)
                            q.push(x);
                    }
                }
            }
        }
    }
};