#include<iostream>
#include<vector>

using namespace std;

class Solution {
    /**
     * Given an array of integers nums and an integer k, 
     * return the number of contiguous subarrays where the product of all the elements in the 
     * subarray is strictly less than k.
    */
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int prod = 1;
        int i=0,j=0;
        int subarrayCount = 0;

        for(;j<n;j++) {
            prod *= nums[j];

            if(prod < k) {
                //have to store the count of all subarrays
                subarrayCount += (j - i + 1);
            }
            while(i<j && prod >= k) {
                prod = prod / nums[i];
                i++;
                //store subarray count here
                //if condition is satisfied
                if(prod < k) {
                    subarrayCount += (j - i + 1);
                } 
            }
        }
        return subarrayCount;
    }
};

int main() {
    vector<int> data = {10,5,2,6};
    int k = 100;
    Solution obj;

    cout<<obj.numSubarrayProductLessThanK(data,k);
}