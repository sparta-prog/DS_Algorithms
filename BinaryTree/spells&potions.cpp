#include <iostream>
#include<vector>

using namespace std;

class Solution {
    /**
     * 2300. Successful Pairs of Spells and Potions
     * You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.
     * You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.
     * Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.
    */
   int lowerBound(vector<int>& potions,int target,int low,int high) {
        int index = 0;
        while(low <= high) {
            int mid = low + (high - low)/2;

            if(target <= potions[mid]) {
                index = mid;
                high = mid-1;
            }
            else 
                low = mid + 1;
        }
        return index;
   }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        if(m == 0)
            return {};

        vector<int> result;
        //sort potions array
        sort(potions.begin(),potions.end());

        for(int i=0;i<n;i++) {
            int spell = spells[i];
            //find the value to be searched for
            long long minPotion = ceil(1.0*success/spell);
            //if the value to be searched for
            if(minPotion > potions[m-1]) {
                result.push_back(0);
            }
            //find the lower bound
            int ind = lowerBound(potions,minPotion,0,m-1);
            //store the result
            //count all elements greater than lower bound
            result.push_back(m - ind);
        }
        return result;
    }
};