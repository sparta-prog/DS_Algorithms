#include <iostream>
#include <vector>

using namespace std;

/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.*/

class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &path)
    {
        visited[node] = true;
        path[node] = true;

        for (auto x : adj[node])
        {
            if (!visited[x])
            {
                bool result = dfs(x, adj, visited, path);
                if(result == true) {
                    return result;
                }
            }
            else if (visited[x] == true && path[x] == true)
            {
                return true;
            }
        }

        // set path to false
        path[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // check cycle in a directed graph first
        // if cycle exists then topological sort not possible
        // implement topological sort
        int n = prerequisites.size();

        if (n == 0)
        {
            if (numCourses > 0)
            {
                return true;
            }

            return false;
        }

        // construct adj list
        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < n; i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);

        bool cycle = false;
        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == false)
            {
                cycle = dfs(i, adj, visited, path);
                // if cycle found
                if(cycle == true)
                    break;
            }
        }

        return (cycle == true) ? false : true;
    }
};


int main() {
    // Create an instance of the Solution class
    Solution solution;
    
    // Define test case input
    int numCourses = 5;
    vector<vector<int>> prerequisites = {{1, 4}, {2, 4}, {3, 1}, {3, 2}};
    
    // Call the canFinish method
    bool result = solution.canFinish(numCourses, prerequisites);
    
    // Output the result
    cout<<result;

    return 0;
}