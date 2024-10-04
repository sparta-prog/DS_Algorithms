#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findLen(vector<int>& nums, int target, int p) {
        int n = nums.size();
        int i = 0, sum = 0, len = INT_MAX;

        //have to find a subarray
        //where n*p + rem exists

        unordered_map<int,int> pref;
        pref[0] = -1;
        
        for(int j=0;j<n;j++) {
            sum = (sum + nums[j]) % p;
            
            int rem = (sum - target + p)%p;

            if(pref.find(rem) != pref.end()) {
                len = min(len, j - pref[rem]);
            }

            pref[sum] = j;
        }
        
        return len;
    }

    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        if(n == 0)
            return -1;

        long long sum = 0;

        for(int& x: nums) {
            sum += x;
        }

        int target = sum % p;


        if(target == 0) {
            return 0;
        }
        //now find a subarray such that
        //sum == target 

        int len = -1;

        len = findLen(nums,target,p);

        return (len==INT_MAX||len == n)?-1:len;
    }
};

int main() {
    vector<int> data = {26,19,11,14,18,4,7,1,30,23,19,8,10,6,26,3};
    int p = 26;

    Solution obj;
    cout<<obj.minSubarray(data,p);
}