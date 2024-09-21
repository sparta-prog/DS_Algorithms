#include<iostream>
#include<vector>

using namespace std;
class Solution {
    private:
    int util(int ind, vector<int>& prices, int k, int buy, vector<vector<vector<int>>> &dp) {
        //base case
        if(ind >= prices.size() || k == 0) {
            return 0;
        }
        if(dp[ind][k][buy] != -1) {
            return dp[ind][k][buy];
        }

        int profit = 0;
        if(buy == 1) {
            //buy
            int op1 = -prices[ind] + util(ind+1, prices,k,0,dp);
            //skip
            int op2 = util(ind+1,prices,k,1,dp);

            profit = max(op1,op2);
        }
        else if(buy == 0) {
            //sell
            int op1 = prices[ind] + util(ind+1,prices,k-1,1,dp);
            //skip
            int op2 = util(ind+1,prices,k,0,dp);

            profit = max(op1,op2);
        }
        return dp[ind][k][buy] = profit;
    }
    public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 0) {
            return 0;
        }
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return util(0,prices,k,1,dp);
    }
};

int main() {
    vector<int> prices = {3,2,6,5,0,3};
    int k = 2;

    Solution obj;

    cout<<obj.maxProfit(k,prices);
}