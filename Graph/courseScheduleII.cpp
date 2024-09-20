#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;
/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites{i} = {ai, bi} indicates that you must take course bi first if you want to take course ai.

For example, the pair {0, 1}, indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.*/

class schedule
{
public:
    bool util(int node, unordered_map<int,vector<int>> &adj, stack<int> &path, vector<int> &visited, vector<int> &recPath)
    {
        // mark visited
        visited[node] = true;
        recPath[node] = true;

        for (auto x : adj[node])
        {
            if (visited[x] == false)
            {
                bool cycleDetected = util(x, adj, path, visited, recPath);
                if (cycleDetected == true)
                {
                    return true;
                }
            }
            else if (visited[x] == true && recPath[x])
            {
                // check recursion path
                return true;
            }
        }
        // store the stack path
        path.push(node);

        // set the inRecursion to false
        recPath[node] = false;
        return false;
    }
    
    vector<int> findOrder(int courses, vector<vector<int>> &pre)
    {
        // b -> a

        unordered_map<int,vector<int>> adj;

        for (auto &x : pre)
        {
            int a = x[0];
            int b = x[1];
            adj[b].push_back(a);
        }

        vector<int> visited(courses, false);
        vector<int> recPath(courses, false);
        vector<int> result;
        stack<int> path;

        bool cycleDetected = false;
        for (int node = 0; node < courses; node++)
        {
            if(!visited[node])
                cycleDetected = util(node, adj, path, visited, recPath);

            if (cycleDetected == true)
            {
                return {};
            }
        }

        while (!path.empty())
        {
            result.push_back(path.top());
            path.pop();
        }
        return result;
    }
};
int main()
{
    int courses = 4;
    vector<vector<int>> pre = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    schedule obj;

    vector<int> sortedOrder = obj.findOrder(courses, pre);

    for (auto x : sortedOrder)
    {
        cout << x << " ";
    }
    return 0;
}
