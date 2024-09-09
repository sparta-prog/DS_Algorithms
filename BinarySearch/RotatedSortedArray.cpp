#include <iostream>
#include <vector>

using namespace std;
/*There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        if(n == 0)
            return -1;

        int low=0, high = n-1;

        int index = -1;

        while(low <= high) {
            int mid = low + (high - low)/2;

            if(nums[mid] == target){
                return mid;
            }

            else if(nums[low] <= nums[mid]) {
                //left half is sorted
                if(nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            else {

                //right half is sorted
                if(nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return index;
    }
};

int main() {

    Solution obj;

    vector<int> data1 = {4,5,6,7,0,1,2};
    int target1 = 0;

    //cout<<obj.search(data1,target1)<<endl;

    vector<int> data2 = {4,5,6,7,0,1,2};
    int target2 = 3;

    //cout<<obj.search(data2,target2)<<endl;

    vector<int> data3 = {5,1,3};
    int target3 = 5;

    cout<<obj.search(data3,target3)<<endl;
}