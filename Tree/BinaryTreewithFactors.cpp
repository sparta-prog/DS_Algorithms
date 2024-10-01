#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/**
 * Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.
 * We make a binary tree using these integers, and each number may be used for any number of times. 
 * Each non-leaf node's value should be equal to the product of the values of its children.
 * Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.
*/
class Solution {
    const int mod = 1e9 + 7;
public:
    int countTrees(vector<int>&arr,unordered_map<int,int> mp) {
        //start from i=1
        int n = arr.size();

        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(arr[i] % arr[j] == 0) {
                    int lc = arr[j];
                    //check for the right child
                    int rc = arr[i]/arr[j];

                    if(mp.find(rc) != mp.end()) {
                        mp[arr[i]] += (mp[lc]*mp[rc]) % mod;
                    }
                }
            }
        }

        int treeCount = 0;

        for(auto it:mp) {
            treeCount = (treeCount + (it.second)) % mod;
        }

        return treeCount;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();

        if(n == 0)
            return 0;

        //sort the array for avoiding unecessary compute
        sort(arr.begin(),arr.end());
        
        unordered_map<int,int> mp;

        for(int& x:arr) {
            mp[x]++;
        }

        return countTrees(arr,mp);
    }
};

int main() {
    vector<int> data = {2,4,5,10};
    Solution obj;

    cout<<obj.numFactoredBinaryTrees(data);
}