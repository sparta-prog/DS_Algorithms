#include <iostream>
#include <vector>

using namespace std;

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    int helper(vector<int> &nums, int i,vector<int> &memo) {

        if(i >= nums.size()) {
            return 0;
        }

        if(memo[i] != -1) {
            return memo[i];
        }

        int pick = 0, dontPick = 0;
        pick = nums[i] + helper(nums,i+2,memo);

        dontPick = helper(nums, i + 1,memo);
        
        return memo[i] = max(pick,dontPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0)
            return 0;
        
        vector<int> memo (n, -1);
        return helper(nums,0,memo);
    }
};

int main() {
    Solution obj;
    vector<int> data = {2,7,9,3,1};

    cout<<obj.rob(data);
}