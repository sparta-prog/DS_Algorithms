#include<iostream>
#include<vector>

using namespace std;

/**
 * Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:
 * Append the character '0' zero times.
 * Append the character '1' one times.
 * This can be performed any number of times.
 * A good string is a string constructed by the above process having a length between low and high (inclusive).
 * Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.
*/

class Solution{
    int L, H;
    int countZero,countOne;
    const int mod = 1e9 + 7;
    public:
    /**
     * Time complexity -> O(H)
     * Space complexity -> O(H)
    */
    //helper function to calculate result
    int util(int len,vector<int> &dp) {
        if(len > H) {
            return 0;
        }
        //memoize
        if(dp[len] != -1) {
            return dp[len];
        }
        bool addCurrent = false;
        if(L <= len && len <= H) {
            //if len is acceptable
            //add the current and go to left and right calls
            addCurrent = true;
        }
        //recursive calls to 0
        int addZero = util(len + countZero,dp);
        //recursive calls to 1
        int addOne = util(len + countOne,dp);

        return dp[len] = (addCurrent + addZero + addOne)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        L = low, H = high;
        countZero = zero, countOne = one;
        vector<int> dp(H+1,-1);
        //initial length is 0
        return util(0,dp);
    }
};

int main() {
    int low = 2, high = 3, zero = 1, one = 2;
    Solution obj;

    cout<<obj.countGoodStrings(low,high,zero,one);
}