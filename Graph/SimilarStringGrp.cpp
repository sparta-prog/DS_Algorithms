#include<iostream>
#include<vector>

using namespace std;

/**
 * Two strings, X and Y, are considered similar if either they are identical or we can make them equivalent by swapping at most two letters (in distinct positions) within the string X.
 * 
 * For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".
 * 
 * Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar
 * Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.
 * 
 * We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?
*/

class Solution {
    //function to check if strings are similar as per the question definition
    bool isSimilar(string &a, string &b) {
        int m = a.size();
        int n = b.size();
        int diff = 0;
        if(m != n)
            return false;

        for(int i=0;i<n;i++) {
            if(a[i] != b[i])
                diff++;
        }

        return (diff==2 || diff==0)?true:false;
    }
    void dfs(int node,vector<bool>& visited,vector<vector<int>>& adj) {
        visited[node] = true;

        for(int neighbour : adj[node]) {
            if(visited[neighbour] == false)
                dfs(neighbour,visited,adj);
        }
        return;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int groups = 0;
        //edge case handling
        if(n == 0)
            return 0;

        vector<vector<int>> adj(n);
        //construct adjacency list
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(isSimilar(strs[i],strs[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        //dfs function to check number of components
        vector<bool> visited(n,false);
        
        for(int node = 0;node<n;node++) {
            if(visited[node] == false) {
                dfs(node,visited,adj);
                groups++;
            }
        }
        return groups;
    }
};

int main() {
    vector<string> data = {"tars","rats","arts","star"};
    Solution obj;

    cout<<obj.numSimilarGroups(data);
}