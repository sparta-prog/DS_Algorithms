#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Solution {
    typedef pair<int,int> p;
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        if(n == 0)
            return -1;

        long long cumSum = 0;
        int result = INT_MAX;
        deque<p>  q;
        q.push_back({0,-1});

        for(int i=0;i<n;i++) {
            cumSum += nums[i];

            int checker = cumSum - k;
            while(!q.empty() && checker >= q.front().first) {
                result = min(result,i - q.front().second);
                q.pop_front();
            }

            while(!q.empty() && q.back().first>cumSum) {
                q.pop_back();
            }
            
            q.push_back({cumSum,i});
        }
        return (result == INT_MAX)?-1:result;
    }
};

int main() {
    Solution obj;
    vector<int> data = {-100000,-100000,-100000,-100000,-100000,-100000,-100000,-100000,-100000,-100000,-100000,-100000,-100000,-100000,-100000,-100000,-100000};
    int k = 1000000000;

    cout<<obj.shortestSubarray(data,k);
}