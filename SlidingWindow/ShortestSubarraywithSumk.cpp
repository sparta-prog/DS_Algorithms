#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/**
 * Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
 * A subarray is a contiguous part of an array.
*/
/**
 * A straight forward sliding window is not applicable if there are negative elements
*/
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0)
            return 0;

        //store length
        int minLen = INT_MAX;
        unordered_map<int,int> mp;
        //store 0 initially
        mp[0] = 1;
        int prefixSum = 0,ans = 0;
        //do the prefix logic
        for(int j=0;j<n;j++) {
            prefixSum += nums[j];
            
            if(mp.find(prefixSum - k) != mp.end()) {
                ans+=mp[prefixSum - k];
            }
            //update map
            mp[prefixSum]++;
        }
        return ans;
    }
};

int main() {
    vector<int> data = {8,-4,4,3,1,2,2};
    int k = 4;
    Solution obj;

    cout<<obj.shortestSubarray(data,k);
}