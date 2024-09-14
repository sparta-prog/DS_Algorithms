#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0)
            return 0;
        
        if(n == 1) {
            return nums[0];
        }

        if(n == 2){
            return max(nums[0],nums[1]);
        }

        int prevPrev = nums[0];
        int prev = max(nums[0],nums[1]);

        for(int i=2;i<n;i++) {
            int skip = prev;
            int steal = prevPrev;

            int curr = max(skip , steal + nums[i]);
            prevPrev = prev;
            prev = curr;
        }
        return prev;
    }
};

int main() {
    Solution obj;
    vector<int> data = {2,7,9,3,1};

    cout<<obj.rob(data);
}