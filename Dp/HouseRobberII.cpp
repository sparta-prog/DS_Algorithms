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
    int solver(vector<int> &nums,int start,int end) {
        if(start == end) {
            return nums[start];
        }
        
        int prevPrev = 0;
        int prev = 0;

        for(int i=start;i<=end;i++) {
            int skip = prev;
            int steal = prevPrev;

            int curr = max(skip , steal + nums[i]);
            prevPrev = prev;
            prev = curr;
        }
        return prev;
    }

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

        //if you rob the first house you cant rob the last
        //so array size reduced
        //if you start from
        return max(solver(nums,1,n-1),solver(nums,0,n-2));
    }
};

int main() {
    Solution obj;
    vector<int> data = {2,7,9,3,1};

    cout<<obj.rob(data);
}